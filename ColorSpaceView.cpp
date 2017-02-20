#include "StdAfx.h"
#include "ColorSpaceView.h"
#include "gl/glu.h"

static void qNormalizeAngle(int &angle)
{
	while (angle < 0)
		angle += 360;
	while (angle > 360 * 16)
		angle -= 360;
}

ColorSpaceView::~ColorSpaceView(void)
{
}

void ColorSpaceView::resizeGL( int width, int height )
{
	int side = qMin(width, height);
	glViewport((width - side) / 2, (height - side) / 2, side, side);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// glOrtho(-0.5, +0.5, -0.5, +0.5, 4.0, 15.0);
	gluPerspective(20, 1.0, 0.5, 20);
	glMatrixMode(GL_MODELVIEW);
}

void ColorSpaceView::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -5.0);
	glRotatef(xRot, 1.0, 0.0, 0.0);
	glRotatef(yRot, 0.0, 1.0, 0.0);
	glRotatef(zRot, 0.0, 0.0, 1.0);
	glTranslatef(-0.5,-0.5,-0.5);

	glLineWidth(0.5f);
	glColor3f(0.5f, 0.5f, 0.5f);
	glBegin(GL_LINES);
	// x
	glVertex3f(0.0f,0.0f,0.0f);	glVertex3f(1.0f,0.0f,0.0f);
	glVertex3f(0.0f,1.0f,0.0f);	glVertex3f(1.0f,1.0f,0.0f);
	glVertex3f(0.0f,0.0f,1.0f);	glVertex3f(1.0f,0.0f,1.0f);
	glVertex3f(0.0f,1.0f,1.0f);	glVertex3f(1.0f,1.0f,1.0f);

	// y
	glVertex3f(0.0f,0.0f,0.0f);	glVertex3f(0.0f,1.0f,0.0f);
	glVertex3f(1.0f,0.0f,0.0f);	glVertex3f(1.0f,1.0f,0.0f);
	glVertex3f(0.0f,0.0f,1.0f);	glVertex3f(0.0f,1.0f,1.0f);
	glVertex3f(1.0f,0.0f,1.0f);	glVertex3f(1.0f,1.0f,1.0f);

	// z
	glVertex3f(0.0f,0.0f,0.0f);	glVertex3f(0.0f,0.0f,1.0f);
	glVertex3f(1.0f,0.0f,0.0f);	glVertex3f(1.0f,0.0f,1.0f);
	glVertex3f(0.0f,1.0f,0.0f);	glVertex3f(0.0f,1.0f,1.0f);
	glVertex3f(1.0f,1.0f,0.0f);	glVertex3f(1.0f,1.0f,1.0f);
	glEnd();

	glPointSize(1.0f);
	glBegin(GL_POINTS);
	for (int i = 0; i < m_samples.size(); ++i)
	{
		QVector3D& sample = m_samples[i];
		glColor3f(sample.x(), sample.y(), sample.z());
		glVertex3f(sample.x(), sample.y(), sample.z());
	}
	glEnd();

	glPointSize(4.0f);
	glBegin(GL_POINTS);
	for (int i = 0; i < m_som1d.size(); ++i)
	{
		QVector3D& node = m_som1d[i];
		glColor3f(node.x(), node.y(), node.z());
		glVertex3f(node.x(), node.y(), node.z());
	}
	glEnd();
	
	// draw som2d
	glBegin(GL_QUADS);
	for (int row = 0; row < m_som2dSize[1]-1; ++row)
	{
		for (int col = 0; col < m_som2dSize[0]-1; ++col)
		{
			QVector3D& node00 = getSomNode2D(row, col);
			QVector3D& node01 = getSomNode2D(row, col+1);
			QVector3D& node10 = getSomNode2D(row+1, col);
			QVector3D& node11 = getSomNode2D(row+1, col+1);
			glColor3f(node00.x(), node00.y(), node00.z());
			glVertex3f(node00.x(),node00.y(),node00.z());
			glVertex3f(node01.x(),node01.y(),node01.z());
			glVertex3f(node11.x(),node11.y(),node11.z());
			glVertex3f(node10.x(),node10.y(),node10.z());
		}
	}
	glEnd();

	glBegin(GL_LINES);
	glLineWidth(0.5f);
	for (int row = 0; row < m_som2dSize[1]; ++row)
	{
		for (int col = 0; col < m_som2dSize[0]-1; ++col)
		{
			QVector3D& node0 = getSomNode2D(row, col);
			QVector3D& node1 = getSomNode2D(row, col+1);
			glColor3f(node0.x()+0.3, node0.y()+0.3, node0.z()+0.3);
			glVertex3f(node0.x(), node0.y(), node0.z());
			glVertex3f(node1.x(), node1.y(), node1.z());
		}
	}
	for (int row = 0; row < m_som2dSize[1]-1; ++row)
	{
		for (int col = 0; col < m_som2dSize[0]; ++col)
		{
			QVector3D& node0 = getSomNode2D(row, col);
			QVector3D& node1 = getSomNode2D(row+1, col);
			glColor3f(node0.x()+0.3, node0.y()+0.3, node0.z()+0.3);
			glVertex3f(node0.x(), node0.y(), node0.z());
			glVertex3f(node1.x(), node1.y(), node1.z());
		}
	}
	glEnd();
}

void ColorSpaceView::mousePressEvent( QMouseEvent *event )
{
	lastPos = event->pos();
}

void ColorSpaceView::mouseMoveEvent( QMouseEvent *event )
{
	int dx = event->x() - lastPos.x();
	int dy = event->y() - lastPos.y();

	if (event->buttons() & Qt::LeftButton) {
		setXRotation(xRot + 0.5 * dy);
		setYRotation(yRot + 0.5 * dx);
	} else if (event->buttons() & Qt::RightButton) {
// 		setXRotation(xRot + 0.5 * dy);
// 		setZRotation(zRot + 0.5 * dx);
	}
	lastPos = event->pos();
}

ColorSpaceView::ColorSpaceView( QWidget *parent /*= 0*/ ) :QGLWidget(parent)
{
	xRot = 45;
	yRot = 45;
	zRot = 0;
	m_som2dSize[0] = m_som2dSize[1] = 0;
}

void ColorSpaceView::setXRotation( int angle )
{
	qNormalizeAngle(angle);
	if (angle != xRot) {
		xRot = angle;
		emit xRotationChanged(angle);
		updateGL();
	}
}

void ColorSpaceView::setYRotation( int angle )
{
	qNormalizeAngle(angle);
	if (angle != yRot) {
		yRot = angle;
		emit yRotationChanged(angle);
		updateGL();
	}
}

void ColorSpaceView::setZRotation( int angle )
{
	qNormalizeAngle(angle);
	if (angle != zRot) {
		zRot = angle;
		emit zRotationChanged(angle);
		updateGL();
	}
}

void ColorSpaceView::initializeGL()
{
	qglClearColor(QColor(255,255,255,255));

	glEnable(GL_DEPTH_TEST);
	//glEnable(GL_CULL_FACE);
	glShadeModel(GL_SMOOTH);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

// 	glEnable(GL_POINT_SMOOTH);
// 	glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
	glEnable(GL_LINE_SMOOTH);
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 

	glEnable(GL_POLYGON_OFFSET_FILL);
	glPolygonOffset(1.0,1.0);
// 	glEnable(GL_LIGHTING);
// 	glEnable(GL_LIGHT0);
	//   glEnable(GL_MULTISAMPLE);
// 	static GLfloat lightPosition[4] = { 0.5, 5.0, 7.0, 1.0 };
// 	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
}

void ColorSpaceView::setSamples( const QVector<QVector3D>& sample )
{
	m_samples = sample;
	updateGL();
}

void ColorSpaceView::setSom2D( const QVector<QVector3D>& som2d, int width, int height )
{
	m_som2d = som2d;
	m_som2dSize[0] = width;
	m_som2dSize[1] = height;
	updateGL();
}

void ColorSpaceView::setSom1D( const QVector<QVector3D>& som1d )
{
	m_som1d = som1d;
	updateGL();
}
