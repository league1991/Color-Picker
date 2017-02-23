#include "stdafx.h"
#include "colorpicker.h"

ColorPicker::ColorPicker(QWidget *parent, Qt::WFlags flags)
	: QWidget(parent, flags)
{
	ui.setupUi(this);

	connect(ui.computeButton, SIGNAL(clicked()), this, SLOT(onCompute()));
	connect(ui.openButton, SIGNAL(clicked()), this, SLOT(onOpen()));
	connect(ui.pasteButton, SIGNAL(clicked()), this, SLOT(onGetFromClipboard()));
	connect(ui.brightnessSlider, SIGNAL(valueChanged(int)), this, SLOT(onChangeBrightness(int)));
	connect(ui.saturationSlider, SIGNAL(valueChanged(int)), this, SLOT(onChangeSaturation(int)));
	connect(ui.som1DLabel, SIGNAL(selectColor(QColor)), this, SLOT(onSelectColor(QColor)));
	connect(ui.som2DLabel, SIGNAL(selectColor(QColor)), this, SLOT(onSelectColor(QColor)));
	connect(ui.clearButton, SIGNAL(clicked()), this, SLOT(onClearColors()));

	QSampleLabel* samples[] = {
		ui.colorSlot_1,		ui.colorSlot_2,		ui.colorSlot_3,		ui.colorSlot_4,
		ui.colorSlot_5,		ui.colorSlot_6,		ui.colorSlot_7,		ui.colorSlot_8,
		ui.colorSlot_9,		ui.colorSlot_10,	ui.colorSlot_11,	ui.colorSlot_12,
		ui.colorSlot_13,	ui.colorSlot_14,	ui.colorSlot_15,	ui.colorSlot_16,
		ui.colorSlot_17,	ui.colorSlot_18,	ui.colorSlot_19,	ui.colorSlot_20,
		ui.colorSlot_21,	ui.colorSlot_22,	ui.colorSlot_23,	ui.colorSlot_24,
		ui.colorSlot_25,	ui.colorSlot_26,	ui.colorSlot_27,	ui.colorSlot_28,
		ui.colorSlot_29,	ui.colorSlot_30,	ui.colorSlot_31,	ui.colorSlot_32,
		ui.colorSlot_33,	ui.colorSlot_34,	ui.colorSlot_35,	ui.colorSlot_36,
		ui.colorSlot_37,	ui.colorSlot_38,	ui.colorSlot_39,	ui.colorSlot_40,
	};
	for (int i = 0; i < sizeof(m_samples)/sizeof(QSampleLabel*); ++i)
	{
		m_samples[i] = samples[i];
		connect(m_samples[i], SIGNAL(selectColor(QSampleLabel*)), this, SLOT(onGetColorValue(QSampleLabel*)));
	}
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

void ColorPicker::onChangeBrightness(int v)
{
	float maxValue = ui.brightnessSlider->maximum();
	float minValue = ui.brightnessSlider->minimum();
	float value = ui.brightnessSlider->value();
	float ratio = (value - minValue) / (maxValue - minValue);
	ratio = ratio * 2.f - 1.0f;
	ratio *= 0.5f;
	ui.som1DLabel->setBrightness(ratio);
	ui.som2DLabel->setBrightness(ratio);
}

void ColorPicker::onSelectColor( QColor color )
{
	ui.colorLabel->setColor(color);
	onGetColorValue(ui.colorLabel);
}

void ColorPicker::onGetColorValue( QSampleLabel* label )
{
	if (label)
	{
		QColor color = label->getColor();
		int v0,v1,v2;
		color.getRgb(&v0,&v1,&v2);
		ui.rgbEdit->setText(QString("%1, %2, %3").arg(v0).arg(v1).arg(v2));

		color.getHsv(&v0,&v1,&v2);
		ui.hsvEdit->setText(QString("%1, %2, %3").arg(v0).arg(v1).arg(v2));

		color.getHsl(&v0,&v1,&v2);
		ui.hslEdit->setText(QString("%1, %2, %3").arg(v0).arg(v1).arg(v2));

		for (int i = 0; i < sizeof(m_samples)/sizeof(QSampleLabel*); ++i)
		{
			m_samples[i]->setSelected(m_samples[i] == label);
		}
	}
}

void ColorPicker::onChangeSaturation( int v )
{
	float maxValue = ui.saturationSlider->maximum();
	float minValue = ui.saturationSlider->minimum();
	float value = ui.saturationSlider->value();
	float ratio = (value - minValue) / (maxValue - minValue);
	ratio = ratio * 2.f - 1.0f;
	ratio *= 0.5f;
	ui.som1DLabel->setSaturation(ratio);
	ui.som2DLabel->setSaturation(ratio);
}

void ColorPicker::onClearColors()
{
	for (int i = 0; i < sizeof(m_samples)/sizeof(QSampleLabel*); ++i)
	{
		m_samples[i]->setColor(QColor(255,255,255));
	}
}

