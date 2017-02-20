#include "stdafx.h"
#include "colorpicker.h"

ColorPicker::ColorPicker(QWidget *parent, Qt::WFlags flags)
	: QWidget(parent, flags)
{
	ui.setupUi(this);

	connect(ui.computeButton, SIGNAL(clicked()), this, SLOT(onCompute()));
	connect(ui.openButton, SIGNAL(clicked()), this, SLOT(onOpen()));
	connect(ui.pasteButton, SIGNAL(clicked()), this, SLOT(onGetFromClipboard()));
}

ColorPicker::~ColorPicker()
{

}

void ColorPicker::onCompute()
{
	Histogram hist(m_image);
	hist.compute(32);
	const QVector<QVector3D>& samples = hist.binColors();

	QVector<QVector3D> randSamples = samples;
	srand(clock());
	for(int i=randSamples.size()-1; i>=1; i--)  
	{
		int j = rand()%(i+1);
		QVector3D sample = randSamples[i];
		randSamples[i] = randSamples[j];
		randSamples[j] = sample;
	}
	const int dim1D = 64;
	const int dim2D = 64;
	SOM som1d(SOM::SOM_1D, dim1D, randSamples);
	SOM som2d(SOM::SOM_2D, dim2D, randSamples);

	som1d.train();
	som2d.train();

	ui.som1DLabel->setResult(som1d.getNodeAsPixels(), som1d.getNodes());
	ui.som2DLabel->setResult(som2d.getNodeAsPixels(), som2d.getNodes(), dim2D, dim2D);

	ui.glWidget->setSamples(randSamples);
	ui.glWidget->setSom1D(som1d.getNodes());
	ui.glWidget->setSom2D(som2d.getNodes(), dim2D, dim2D);
}

void ColorPicker::onOpen()
{
	QString path = QFileDialog::getOpenFileName(this,
		tr("Open File"),
		".",
		tr("Image Files(*.*)"));

	if (path.isEmpty())
	{
		return;
	}

	QByteArray pathByte = path.toLatin1();
	setInputImage(QImage(pathByte.data()));
}

void ColorPicker::setInputImage( const QImage& img )
{
	m_image = img;
	QSize qs = ui.imageLabel->rect().size();
	ui.imageLabel->setPixmap(QPixmap::fromImage(m_image).scaled(qs));
}

void ColorPicker::onGetFromClipboard()
{
	QClipboard *board = QApplication::clipboard();
	setInputImage(board->image());
}

