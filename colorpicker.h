#ifndef COLORPICKER_H
#define COLORPICKER_H

#include <QtGui/QWidget>
#include "ui_colorpicker.h"

class ColorPicker : public QWidget
{
	Q_OBJECT

public:
	ColorPicker(QWidget *parent = 0, Qt::WFlags flags = 0);
	~ColorPicker();

public slots:
	void onOpen();
	void setInputImage(const QImage& img);
	void onGetFromClipboard();
	void onCompute();
	void onChangeBrightness(int value);
	void onChangeSaturation(int value);
	void onSelectColor(QColor color);
	void onGetColorValue(QSampleLabel* label);
private:
	Ui::ColorPickerClass	ui;

	QImage					m_image;
	QSampleLabel*			m_samples[40];
};

#endif // COLORPICKER_H
