#pragma once

class QColorLabel1D: public QLabel
{
	Q_OBJECT
public:
	QColorLabel1D(QWidget *parent = 0);
	void				setResult(const QImage& image, const QVector<QVector3D>& nodes);

	void				paintEvent(QPaintEvent *event);
	void				mouseMoveEvent(QMouseEvent *event);
public slots:
	void				onUpdateColor();
signals:
	void				updateColor();
private:
	int					m_ithColor;
	QImage				m_image;
	QVector<QVector3D>	m_colors;
};

class QColorLabel2D: public QLabel
{
	Q_OBJECT
public:
	QColorLabel2D(QWidget* parent = 0);
	void				setResult(const QImage& image, const QVector<QVector3D>& nodes, int width, int height);
	void				mouseMoveEvent(QMouseEvent *event);
	void				paintEvent(QPaintEvent *event);
public slots:
	void				onUpdateColor();
signals:
	void				updateColor();
private:
	int					m_ithRow, m_ithCol;
	QImage				m_image;
	QVector<QVector3D>	m_colors;
	int					m_width, m_height;
};