#pragma once

class ColorSpaceView: public QGLWidget
{
	Q_OBJECT
public:
	ColorSpaceView(QWidget *parent = 0);
	~ColorSpaceView(void);

	void setSamples(const QVector<QVector3D>& sample);
	void setSom1D(const QVector<QVector3D>& som1d);
	void setSom2D(const QVector<QVector3D>& som2d, int width, int height);

	void initializeGL();
	void resizeGL(int width, int height);
	void paintGL();
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);

	void setXRotation(int angle);
	void setYRotation(int angle);
	void setZRotation(int angle);

signals:
	void xRotationChanged(int angle);
	void yRotationChanged(int angle);
	void zRotationChanged(int angle);

private:
	inline QVector3D&	getSomNode2D(int i, int j){return m_som2d[i*m_som2dSize[0]+j];}
	QVector<QVector3D>	m_samples;

	QVector<QVector3D>	m_som1d;
	QVector<QVector3D>	m_som2d;
	int					m_som2dSize[2];

	QPoint lastPos;
	int xRot;
	int yRot;
	int zRot;
};
