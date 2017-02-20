#include "stdafx.h"

inline int clamp(int x, int minVal, int maxVal)
{
	return x < minVal ? minVal : (x > maxVal ? maxVal : x);
}

void QColorLabel1D::setResult( const QImage& image, const QVector<QVector3D>& nodes )
{
	m_image = image;
	m_colors = nodes;
	QSize size = rect().size();
	setPixmap(QPixmap::fromImage(image).scaled(size));
	emit updateColor();
}

void QColorLabel1D::paintEvent( QPaintEvent *event )
{
	QLabel::paintEvent(event);
	if (m_colors.size())
	{
		QSize size = this->size();
		float rectW = size.width() / float(m_colors.size());
		float rectH = size.height()-2;
		float x = m_ithColor * rectW;
		float y = 1;
		QPainter painter(this);
		painter.setPen(QPen(QBrush(QColor(30,30,30,255)), 1));
		painter.drawRect(QRectF(x,y,rectW, rectH));
	}
}

void QColorLabel1D::mouseMoveEvent( QMouseEvent *event )
{
	if (event->buttons() & Qt::LeftButton)
	{
		QPointF pos = event->posF();
		if (m_colors.size())
		{
			float colorWidth = size().width() / float(m_colors.size());
			m_ithColor = int(pos.x() / colorWidth);
			m_ithColor = clamp(m_ithColor, 0, m_colors.size()-1);
			emit updateColor();
		}
	}
}

QColorLabel1D::QColorLabel1D( QWidget *parent /*= 0*/ ) :QLabel(parent)
{
	m_ithColor = 0;
	connect(this, SIGNAL(updateColor()), this, SLOT(onUpdateColor()));
}

void QColorLabel1D::onUpdateColor()
{
	update();
}

void QColorLabel2D::onUpdateColor()
{
	update();
}

void QColorLabel2D::setResult( const QImage& image, const QVector<QVector3D>& nodes, int width, int height )
{
	m_image = image;
	m_colors = nodes;
	m_width = width;
	m_height = height;

	QSize size = rect().size();
	setPixmap(QPixmap::fromImage(image).scaled(size));
	emit updateColor();
}

QColorLabel2D::QColorLabel2D( QWidget* parent /*= 0*/ ) :QLabel(parent)
{
	m_ithRow = m_ithCol = 0;
	connect(this, SIGNAL(updateColor()), this, SLOT(onUpdateColor()));
}

void QColorLabel2D::mouseMoveEvent( QMouseEvent *event )
{
	if (event->buttons() & Qt::LeftButton)
	{
		QPointF pos = event->posF();
		if (m_colors.size())
		{
			float colorWidth = size().width() / float(m_width);
			float colorHeight = size().height() / float(m_height);
			m_ithRow = int(pos.x() / colorWidth);
			m_ithRow = clamp(m_ithRow, 0, m_width-1);
			m_ithCol = int(pos.y() / colorHeight);
			m_ithCol = clamp(m_ithCol, 0, m_height-1);
			emit updateColor();
		}
	}
}

void QColorLabel2D::paintEvent( QPaintEvent *event )
{
	QLabel::paintEvent(event);
	if (m_colors.size())
	{
		QSize size = this->size();
		float rectW = size.width() / float(m_width);
		float rectH = size.height() / float(m_height);
		float x = m_ithRow * rectW;
		float y = m_ithCol * rectH;
		QPainter painter(this);
		painter.setPen(QPen(QBrush(QColor(30,30,30,255)), 1));
		painter.drawRect(QRectF(x,y,rectW, rectH));
	}
}
