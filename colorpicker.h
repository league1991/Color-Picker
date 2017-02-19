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

private:
	Ui::ColorPickerClass	ui;

	QImage					m_image;
};

#endif // COLORPICKER_H
