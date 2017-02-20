#include "StdAfx.h"
#include "SOM.h"


SOM::SOM( Dimension dim, int gridSize, const QVector<QVector3D>& samples, int seed) :
m_dim(dim), m_gridSize(gridSize), m_samples(samples), m_l0(0.16f), m_seed(seed), m_ithIter(0)
{
	m_lmbd = 0.6f * m_samples.size();
	m_sigma0 = 0.3f * gridSize;
}

SOM::~SOM(void)
{
}

void SOM::init()
{
	srand(m_seed);
	if (m_dim == SOM_1D)
	{
		m_nodes.resize(m_gridSize);
		for (int i = 0; i < m_gridSize; ++i)
		{
			m_nodes[i] = QVector3D(randf(), randf(), randf());
		}
	}
	else if (m_dim == SOM_2D)
	{
		int nNodes = m_gridSize * m_gridSize;
		m_nodes.resize(nNodes);
		for (int i = 0; i < nNodes; ++i)
		{
			m_nodes[i] = QVector3D(randf(), randf(), randf());
		}
	}
	m_ithIter = 0;
}

void SOM::trainStep( int t )
{
	if (t < 0 || t >= m_samples.size())
	{
		return;
	}
	QVector3D& sample = m_samples[t];

	// find nearest node
	int nearestID = 0;
	float nearestDist = FLT_MAX;
	for (int i = 0; i < m_nodes.size(); ++i)
	{
		float dist = (sample - m_nodes[i]).lengthSquared();
		if (dist < nearestDist)
		{
			nearestDist = dist;
			nearestID = i;
		}
	}

	// update weight
	float activeRate = exp(-t/m_lmbd);
	float learningRestraint = m_l0 * activeRate;
	QVector3D& bestNode = m_nodes[nearestID];

	if (m_dim == SOM_1D)
	{
		int bestRow = nearestID;
		for (int ithRow = 0; ithRow < m_gridSize; ++ithRow)
		{
			int dRow = bestRow - ithRow;
			int idDistSq = dRow*dRow;

			float sigma = m_sigma0 * activeRate;
			float theta = exp(-idDistSq / (2.f*sigma * sigma));

			QVector3D& node = m_nodes[ithRow];
			node += learningRestraint * theta * (sample - node);
		}
	}
	else if (m_dim == SOM_2D)
	{
		int bestRow = nearestID / m_gridSize;
		int bestCol = nearestID - bestRow * m_gridSize;

		QVector3D* pNode = &m_nodes[0];
		float sampleX = sample.x();
		float sampleY = sample.y();
		float sampleZ = sample.z();
		float sigma = m_sigma0 * activeRate;
		for (int ithRow = 0; ithRow < m_gridSize; ++ithRow)
		{
			for (int ithCol = 0; ithCol < m_gridSize; ++ithCol, ++pNode)
			{
				int dRow = bestRow - ithRow;
				int dCol = bestCol - ithCol;
				int idDistSq = (dRow*dRow+dCol*dCol);

				float theta = exp(-idDistSq / (2.f*sigma * sigma));

				// *pNode += learningRestraint * theta * (sample - *pNode);
				float nodeX = pNode->x();
				float nodeY = pNode->y();
				float nodeZ = pNode->z();
				float factor = learningRestraint * theta;
				pNode->setX(nodeX + factor *(sampleX - nodeX));
				pNode->setY(nodeY + factor *(sampleY - nodeY));
				pNode->setZ(nodeZ + factor *(sampleZ - nodeZ));
			}
		}
	}
}

void SOM::train()
{
	init();
	while (m_ithIter < m_samples.size())
	{
		trainStep(m_ithIter);
		m_ithIter++;
	}
}

QImage SOM::getNodeAsPixels() const
{
	int nNodes = m_dim == SOM_1D ? m_gridSize : m_gridSize * m_gridSize;
	int width = m_gridSize;
	int height = m_dim == SOM_1D ? 1 : m_gridSize;
	QImage image(width, height, QImage::Format_RGB32);
	unsigned int* pixels = (unsigned int*)image.bits();

	for (int i = 0; i < nNodes; ++i)
	{
		const QVector3D& color = m_nodes[i];
		uchar r = (uchar) (color.x() * 255.f);
		uchar g = (uchar) (color.y() * 255.f);
		uchar b = (uchar) (color.z() * 255.f);
		pixels[i] = (r << 16) | (g << 8) | (b);
	}
	return image;
}
