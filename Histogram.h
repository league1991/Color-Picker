#pragma once

class Histogram
{
public:
	enum ColorSpace
	{
		SPACE_RGB,
	};
	Histogram(const QImage& img, float lowDensity = 0.2f);
	~Histogram(void);

	void					compute(int binDim = 16, ColorSpace space = SPACE_RGB);
	const QVector<int>&		bins(){return m_bins;}
	const QVector<QVector3D>&binColors(){return m_binColors;}

private:
	void					convertColorSpace(ColorSpace space);
	void					computeRange();
	void					computeHistogram(int binDim);
	void					clampLowDensity(int binDim);

	QImage					m_image;
	float					m_lowFreqRatio;

	QVector<QVector3D>		m_colorBuffer;
	QVector3D				m_colorMin;
	QVector3D				m_colorMax;

	QVector<int>			m_bins;
	QVector<QVector3D>		m_binColors;
};
