#pragma once

class QSampleLabel: public QLabel
{
	Q_OBJECT
public:
	QSampleLabel(QWidget *parent = 0);

	void				setColor(QColor color);
	QColor				getColor(){return m_color;}
	void				paintEvent(QPaintEvent *event);
	void				mousePressEvent(QMouseEvent* event);
	void				mouseMoveEvent(QMouseEvent *event);
	void				dragEnterEvent(QDragEnterEvent *event);
	void				dropEvent(QDropEvent *event);
	void				setSelected(bool isSelected);
signals:
	void				selectColor(QSampleLabel* label);
private:
	QColor				m_color;
	bool				m_isSelected;
};

class QColorLabel1D: public QLabel
{
	Q_OBJECT
public:
	QColorLabel1D(QWidget *parent = 0);
	void				setResult(const QImage& image, const QVector<QVector3D>& nodes);
	void				setBrightness(float value);
	void				paintEvent(QPaintEvent *event);
	void				mousePressEvent(QMouseEvent* event);
	void				mouseMoveEvent(QMouseEvent *event);
	void				pickColor(const QPointF& pos);
	QColor				getSelectedColor();
public slots:
	void				onUpdateColor();
signals:
	void				updateColor();
	void				selectColor(QColor color);
private:
	float				m_brightness;
	int					m_ithColor;
	QImage				m_image, m_dispImage;
	QVector<QVector3D>	m_colors;
};

class QColorLabel2D: public QLabel
{
	Q_OBJECT
public:
	QColorLabel2D(QWidget* parent = 0);
	void				setResult(const QImage& image, const QVector<QVector3D>& nodes, int width, int height);
	void				setBrightness(float value);
	void				pickColor(const QPointF& pos);
	void				mouseMoveEvent(QMouseEvent *event);
	void				mousePressEvent(QMouseEvent* event);
	void				paintEvent(QPaintEvent *event);
	QColor				getSelectedColor();
public slots:
	void				onUpdateColor();
signals:
	void				updateColor();
	void				selectColor(QColor color);
private:
	float				m_brightness;
	int					m_ithRow, m_ithCol;
	QImage				m_image, m_dispImage;
	QVector<QVector3D>	m_colors;
	int					m_width, m_height;
};