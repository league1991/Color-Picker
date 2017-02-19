#include "StdAfx.h"
#include "Histogram.h"

Histogram::Histogram(const QImage& img, float lowDensity):m_image(img)
{
	m_lowFreqRatio = lowDensity;
}

Histogram::~Histogram(void)
{
}

void Histogram::convertColorSpace( ColorSpace space )
{
	int nPixels = m_image.width() * m_image.height();
	m_colorBuffer.resize(nPixels);
	if (space == SPACE_RGB)
	{
		const uchar* pPixel = m_image.constBits();
		for (int i = 0; i <nPixels; ++i, pPixel += 4)
		{
			QVector3D color(pPixel[2],pPixel[1],pPixel[0]);
			m_colorBuffer[i] = color / 255.f;
		}
	}
}

void Histogram::computeRange()
{
	float minColor[] = {FLT_MAX, FLT_MAX, FLT_MAX};
	float maxColor[] = {-FLT_MAX, -FLT_MAX, -FLT_MAX};

	for (int i = 0; i < m_colorBuffer.size(); ++i)
	{
		QVector3D& colorVec = m_colorBuffer[i];
		float color[] = {colorVec.x(),colorVec.y(),colorVec.z()};
		for (int j = 0; j < 3; ++j)
		{
			minColor[j] = min(minColor[j], color[j]);
			maxColor[j] = max(maxColor[j], color[j]);
		}
	}

	m_colorMin = QVector3D(minColor[0],minColor[1],minColor[2]);
	m_colorMax = QVector3D(maxColor[0],maxColor[1],maxColor[2]);
}

void Histogram::computeHistogram(int binDim)
{
	int nBins = binDim * binDim * binDim;
	m_bins.resize(nBins);
	m_binColors.resize(nBins);

	for (int i = 0; i < m_bins.size(); ++i)
	{
		m_bins[i] = 0;
		m_binColors[i] = QVector3D(0,0,0);
	}

	QVector3D cellSize = (m_colorMax - m_colorMin) / binDim;
	for (int i = 0; i < m_colorBuffer.size(); ++i)
	{
		QVector3D& color = m_colorBuffer[i];
		QVector3D  dC = color - m_colorMin;
		int nX = min(dC.x() / cellSize.x(), binDim-1);
		int nY = min(dC.y() / cellSize.y(), binDim-1);
		int nZ = min(dC.z() / cellSize.z(), binDim-1);

		int id = nX * binDim * binDim + nY * binDim + nZ;
		m_bins[id]++;
		m_binColors[id] += color;
	}

	for (int i = 0; i < m_bins.size(); ++i)
	{
		if (m_bins[i] > 0)
		{
			m_binColors[i] /= float(m_bins[i]);
		}
	}
}

void Histogram::compute( int binDim /*= 16*/, ColorSpace space /*= SPACE_RGB*/ )
{
	convertColorSpace(space);
	computeRange();
	computeHistogram(binDim);
	clampLowDensity(binDim);
}

void Histogram::clampLowDensity( int binDim )
{
	int nBins = binDim * binDim * binDim;
	float avgBin = m_colorBuffer.size() / float(nBins);
	int minBin = int(m_lowFreqRatio * avgBin);

	QVector<int> bins;
	QVector<QVector3D> binColors;
	for (int i=0; i < nBins; ++i)
	{
		if (m_bins[i] > minBin)
		{
			bins.push_back(m_bins[i]);
			binColors.push_back(m_binColors[i]);
		}
	}

	m_bins = bins;
	m_binColors = binColors;
}
