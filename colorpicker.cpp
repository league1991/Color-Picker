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
	SOM som1d(SOM::SOM_1D, 64, randSamples);
	SOM som2d(SOM::SOM_2D, 32, randSamples);

	som1d.train();
	som2d.train();

	QSize size1 = ui.som1DLabel->rect().size();
	QSize size2 = ui.som2DLabel->rect().size();

	QImage image1 = som1d.getNodeAsPixels();
	QImage image2 = som2d.getNodeAsPixels();
	ui.som1DLabel->setPixmap(QPixmap::fromImage(image1).scaled(size1));
	ui.som2DLabel->setPixmap(QPixmap::fromImage(image2).scaled(size2));

	ui.glWidget->setSamples(randSamples);
	ui.glWidget->setSom1D(som1d.getNodes());
	ui.glWidget->setSom2D(som2d.getNodes(), 32, 32);
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

