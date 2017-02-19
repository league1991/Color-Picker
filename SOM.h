#pragma once

class SOM
{
public:
	enum Dimension{
		SOM_1D,
		SOM_2D
	};

	SOM(Dimension dim, int gridSize, const QVector<QVector3D>& samples, int seed = 12345);
	~SOM(void);

	void					train();

	const QVector<QVector3D>& getNodes()const{return m_nodes;}
	QImage   getNodeAsPixels()const;

private:
	void					init();
	void					trainStep(int t);

	// parameters
	Dimension				m_dim;
	int						m_seed;
	int						m_gridSize;
	float					m_l0;
	float					m_lmbd;
	float					m_sigma0;

	// input data
	QVector<QVector3D>		m_samples;

	// internal data
	QVector<QVector3D>		m_nodes;
	int						m_ithIter;
};
