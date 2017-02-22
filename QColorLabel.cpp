#include "stdafx.h"

template<typename T>
inline T clamp(T x, T minVal, T maxVal)
{
	return (x < minVal) ? minVal : (x > maxVal ? maxVal : x);
}

void brightImage(float brightnessOffset, float saturationOffset, const QImage& srcImg, QImage& dstImg)
{
	QSize size = srcImg.size();
	dstImg = *&QImage(size.width(), size.height(), QImage::Format_ARGB32);
	const QRgb* pSrc = (const QRgb*)srcImg.constBits();
	QRgb* pDst = (QRgb*)dstImg.bits();
	for (int i = 0; i < size.width()*size.height(); ++i, pSrc++, pDst++)
	{
		QColor color(*pSrc);
		qreal h,s,l;
		color.getHslF(&h,&s,&l);
		//l = clamp(l+brightnessOffset,0.0,1.0);
		s = clamp(s+saturationOffset,0.0,1.0);
		color = QColor::fromHslF(h,s,l);

		qreal r0,g0,b0;
		color.getRgbF(&r0,&g0,&b0);
		r0 = clamp(r0+brightnessOffset,0.0,1.0);
		g0 = clamp(g0+brightnessOffset,0.0,1.0);
		b0 = clamp(b0+brightnessOffset,0.0,1.0);
		color = QColor::fromRgbF(r0,g0,b0);
		int r,g,b;
		color.getRgb(&r,&g,&b);
		*pDst = qRgb(r,g,b);
	}
}

void QColorLabel1D::setResult( const QImage& image, const QVector<QVector3D>& nodes )
{
	m_image = image;
	m_colors = nodes;
	emit updateColor();
}

void QColorLabel1D::paintEvent( QPaintEvent *event )
{
	QLabel::paintEvent(event);
	if (m_colors.size())
	{
		QSize size = this->size();
		float rectW = size.width() / float(m_colors.size());
		float rectH = size.height()-1;
		float x = m_ithColor * rectW;
		float y = 0;
		QPainter painter(this);
		painter.setPen(QPen(QBrush(QColor(30,30,30,255)), 1));
		painter.drawRect(QRectF(x,y,rectW, rectH));
	}
}

void QColorLabel1D::mouseMoveEvent( QMouseEvent *event )
{
	if (event->buttons() & Qt::LeftButton)
	{
		pickColor(event->posF());
	}
}

QColorLabel1D::QColorLabel1D( QWidget *parent /*= 0*/ ) :QLabel(parent)
{
	m_ithColor = 0;
	m_brightness = 0.0;
	m_saturation = 0.0;
	connect(this, SIGNAL(updateColor()), this, SLOT(onUpdateColor()));
}

void QColorLabel1D::onUpdateColor()
{
	if (m_image.isNull())
	{
		return;
	}
	QSize size = rect().size();
	brightImage(m_brightness, m_saturation, m_image, m_dispImage);
	setPixmap(QPixmap::fromImage(m_dispImage).scaled(size));

	QColor selectedColor = getSelectedColor();
	emit selectColor(selectedColor);
	update();
}

void QColorLabel1D::setSaturation( float value )
{
	m_saturation = value;
	emit updateColor();
}

void QColorLabel2D::setSaturation( float value )
{
	m_saturation = value;
	emit updateColor();
}

void QColorLabel1D::setBrightness( float value )
{
	m_brightness = value;
	emit updateColor();
}

QColor QColorLabel1D::getSelectedColor()
{
	QColor color;
	if (!m_dispImage.isNull())
	{
		color = m_dispImage.pixel(m_ithColor, 0);
	}
	return color;
}

void QColorLabel1D::mousePressEvent( QMouseEvent* event )
{
	if (event->buttons() & Qt::LeftButton)
	{
		pickColor(event->posF());
	}
}

void QColorLabel1D::pickColor( const QPointF& pos )
{
	if (m_colors.size())
	{
		float colorWidth = size().width() / float(m_colors.size());
		m_ithColor = int(pos.x() / colorWidth);
		m_ithColor = clamp(m_ithColor, 0, m_colors.size()-1);
		update();

		QColor selectedColor = getSelectedColor();
		emit selectColor(selectedColor);
	}
}

void QColorLabel2D::onUpdateColor()
{
	if (m_image.isNull())
	{
		return;
	}
	QSize size = rect().size();
	brightImage(m_brightness, m_saturation, m_image, m_dispImage);
	setPixmap(QPixmap::fromImage(m_dispImage).scaled(size));

	QColor selectedColor = getSelectedColor();
	emit selectColor(selectedColor);
	update();
}

void QColorLabel2D::setResult( const QImage& image, const QVector<QVector3D>& nodes, int width, int height )
{
	m_image = image;
	m_colors = nodes;
	m_width = width;
	m_height = height;
	emit updateColor();
}

QColorLabel2D::QColorLabel2D( QWidget* parent /*= 0*/ ) :QLabel(parent)
{
	m_ithRow = m_ithCol = 0;
	m_brightness = 0.0;
	m_saturation = 0.0;
	connect(this, SIGNAL(updateColor()), this, SLOT(onUpdateColor()));
}

void QColorLabel2D::pickColor(const QPointF& pos)
{
	if (m_colors.size())
	{
		float colorWidth = size().width() / float(m_width);
		float colorHeight = size().height() / float(m_height);
		m_ithRow = int(pos.x() / colorWidth);
		m_ithRow = clamp(m_ithRow, 0, m_width-1);
		m_ithCol = int(pos.y() / colorHeight);
		m_ithCol = clamp(m_ithCol, 0, m_height-1);
		update();

		QColor selectedColor = getSelectedColor();
		emit selectColor(selectedColor);
	}
}

void QColorLabel2D::mousePressEvent(QMouseEvent* event)
{
	if (event->buttons() & Qt::LeftButton)
	{
		pickColor(event->posF());
	}
}

void QColorLabel2D::mouseMoveEvent( QMouseEvent *event )
{
	if (event->buttons() & Qt::LeftButton)
	{
		pickColor(event->posF());
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

void QColorLabel2D::setBrightness( float value )
{
	m_brightness = value;
	emit updateColor();
}

QColor QColorLabel2D::getSelectedColor()
{
	QColor color(255,255,255,255);
	if (!m_dispImage.isNull())
	{
		color = m_dispImage.pixel(m_ithRow, m_ithCol);
	}
	return color;
}

void QSampleLabel::paintEvent( QPaintEvent *event )
{
	QPainter painter(this);
	painter.setBrush(QBrush(m_color));
	if (m_isSelected)
	{
		painter.setPen(QPen(QColor(0,0,0), 8));
	}
	painter.drawRect(rect());

	QLabel::paintEvent(event);
}

void QSampleLabel::dropEvent( QDropEvent *event )
{
	QVariant colorData = event->mimeData()->colorData();
	int colorByte = colorData.toInt();
	m_color.setRgb((QRgb)colorByte);
	event->acceptProposedAction();
	update();
}

void QSampleLabel::mouseMoveEvent( QMouseEvent *event )
{
	if (!(event->buttons() & Qt::LeftButton))
		return;
	QDrag *drag = new QDrag(this);
	QMimeData *mimeData = new QMimeData;
	QRgb rgb = m_color.rgb();
	mimeData->setColorData(QVariant(rgb));
	drag->setMimeData(mimeData);
	Qt::DropAction dropAction = drag->exec(Qt::CopyAction | Qt::MoveAction);
}

void QSampleLabel::setColor( QColor color )
{
	m_color = color;
	update();
}

QSampleLabel::QSampleLabel( QWidget *parent /*= 0*/ ) :QLabel(parent), m_color(255,255,255,255), m_isSelected(false)
{
}

void QSampleLabel::dragEnterEvent( QDragEnterEvent *event )
{
	if (event->mimeData()->hasColor())
		event->acceptProposedAction();
}

void QSampleLabel::mousePressEvent( QMouseEvent* event )
{
	if (event->buttons() & Qt::LeftButton)
	{
		emit selectColor(this);
	}
}

void QSampleLabel::setSelected( bool isSelected )
{
	m_isSelected = isSelected;
	update();
}
