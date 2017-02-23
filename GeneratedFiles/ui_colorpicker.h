/********************************************************************************
** Form generated from reading UI file 'colorpicker.ui'
**
** Created: Thu Feb 23 23:36:20 2017
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLORPICKER_H
#define UI_COLORPICKER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QWidget>
#include <colorspaceview.h>
#include "qcolorlabel.h"

QT_BEGIN_NAMESPACE

class Ui_ColorPickerClass
{
public:
    QLabel *imageLabel;
    QColorLabel1D *som1DLabel;
    QColorLabel2D *som2DLabel;
    QPushButton *computeButton;
    QPushButton *openButton;
    ColorSpaceView *glWidget;
    QPushButton *pasteButton;
    QSlider *brightnessSlider;
    QSampleLabel *colorLabel;
    QSampleLabel *colorSlot_1;
    QLineEdit *rgbEdit;
    QLabel *rgbLabel;
    QLabel *hsvLabel;
    QLabel *hslLabel;
    QLineEdit *hsvEdit;
    QLineEdit *hslEdit;
    QSampleLabel *colorSlot_2;
    QSampleLabel *colorSlot_3;
    QSampleLabel *colorSlot_4;
    QSampleLabel *colorSlot_5;
    QSampleLabel *colorSlot_6;
    QSampleLabel *colorSlot_7;
    QSampleLabel *colorSlot_8;
    QSampleLabel *colorSlot_9;
    QSampleLabel *colorSlot_10;
    QSampleLabel *colorSlot_11;
    QSampleLabel *colorSlot_12;
    QSampleLabel *colorSlot_13;
    QSampleLabel *colorSlot_14;
    QSampleLabel *colorSlot_15;
    QSampleLabel *colorSlot_16;
    QSampleLabel *colorSlot_17;
    QSampleLabel *colorSlot_18;
    QSampleLabel *colorSlot_19;
    QSampleLabel *colorSlot_20;
    QSampleLabel *colorSlot_21;
    QSampleLabel *colorSlot_22;
    QSampleLabel *colorSlot_23;
    QSampleLabel *colorSlot_24;
    QSampleLabel *colorSlot_25;
    QSampleLabel *colorSlot_26;
    QSampleLabel *colorSlot_27;
    QSampleLabel *colorSlot_28;
    QSampleLabel *colorSlot_29;
    QSampleLabel *colorSlot_30;
    QSampleLabel *colorSlot_31;
    QSampleLabel *colorSlot_32;
    QSampleLabel *colorSlot_33;
    QSampleLabel *colorSlot_34;
    QSampleLabel *colorSlot_35;
    QSampleLabel *colorSlot_36;
    QSampleLabel *colorSlot_37;
    QSampleLabel *colorSlot_38;
    QSampleLabel *colorSlot_39;
    QSampleLabel *colorSlot_40;
    QSlider *saturationSlider;
    QPushButton *clearButton;

    void setupUi(QWidget *ColorPickerClass)
    {
        if (ColorPickerClass->objectName().isEmpty())
            ColorPickerClass->setObjectName(QString::fromUtf8("ColorPickerClass"));
        ColorPickerClass->resize(1059, 500);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ColorPickerClass->sizePolicy().hasHeightForWidth());
        ColorPickerClass->setSizePolicy(sizePolicy);
        ColorPickerClass->setMinimumSize(QSize(1000, 500));
        ColorPickerClass->setMaximumSize(QSize(1200, 500));
        imageLabel = new QLabel(ColorPickerClass);
        imageLabel->setObjectName(QString::fromUtf8("imageLabel"));
        imageLabel->setGeometry(QRect(20, 10, 201, 181));
        imageLabel->setFrameShape(QFrame::Box);
        som1DLabel = new QColorLabel1D(ColorPickerClass);
        som1DLabel->setObjectName(QString::fromUtf8("som1DLabel"));
        som1DLabel->setGeometry(QRect(249, 10, 431, 31));
        som1DLabel->setFrameShape(QFrame::NoFrame);
        som2DLabel = new QColorLabel2D(ColorPickerClass);
        som2DLabel->setObjectName(QString::fromUtf8("som2DLabel"));
        som2DLabel->setGeometry(QRect(249, 49, 431, 431));
        som2DLabel->setFrameShape(QFrame::NoFrame);
        computeButton = new QPushButton(ColorPickerClass);
        computeButton->setObjectName(QString::fromUtf8("computeButton"));
        computeButton->setGeometry(QRect(20, 240, 201, 23));
        openButton = new QPushButton(ColorPickerClass);
        openButton->setObjectName(QString::fromUtf8("openButton"));
        openButton->setGeometry(QRect(20, 210, 91, 23));
        glWidget = new ColorSpaceView(ColorPickerClass);
        glWidget->setObjectName(QString::fromUtf8("glWidget"));
        glWidget->setGeometry(QRect(20, 280, 201, 201));
        pasteButton = new QPushButton(ColorPickerClass);
        pasteButton->setObjectName(QString::fromUtf8("pasteButton"));
        pasteButton->setGeometry(QRect(130, 210, 91, 23));
        brightnessSlider = new QSlider(ColorPickerClass);
        brightnessSlider->setObjectName(QString::fromUtf8("brightnessSlider"));
        brightnessSlider->setGeometry(QRect(700, 10, 22, 471));
        brightnessSlider->setMaximum(24);
        brightnessSlider->setSingleStep(1);
        brightnessSlider->setValue(12);
        brightnessSlider->setOrientation(Qt::Vertical);
        brightnessSlider->setTickPosition(QSlider::TicksBothSides);
        brightnessSlider->setTickInterval(3);
        colorLabel = new QSampleLabel(ColorPickerClass);
        colorLabel->setObjectName(QString::fromUtf8("colorLabel"));
        colorLabel->setGeometry(QRect(780, 10, 100, 100));
        colorLabel->setFrameShape(QFrame::Box);
        colorSlot_1 = new QSampleLabel(ColorPickerClass);
        colorSlot_1->setObjectName(QString::fromUtf8("colorSlot_1"));
        colorSlot_1->setGeometry(QRect(780, 130, 41, 31));
        colorSlot_1->setAcceptDrops(true);
        colorSlot_1->setFrameShape(QFrame::NoFrame);
        colorSlot_1->setFrameShadow(QFrame::Plain);
        rgbEdit = new QLineEdit(ColorPickerClass);
        rgbEdit->setObjectName(QString::fromUtf8("rgbEdit"));
        rgbEdit->setGeometry(QRect(930, 20, 91, 20));
        rgbEdit->setReadOnly(true);
        rgbLabel = new QLabel(ColorPickerClass);
        rgbLabel->setObjectName(QString::fromUtf8("rgbLabel"));
        rgbLabel->setGeometry(QRect(890, 20, 21, 21));
        hsvLabel = new QLabel(ColorPickerClass);
        hsvLabel->setObjectName(QString::fromUtf8("hsvLabel"));
        hsvLabel->setGeometry(QRect(890, 50, 21, 21));
        hslLabel = new QLabel(ColorPickerClass);
        hslLabel->setObjectName(QString::fromUtf8("hslLabel"));
        hslLabel->setGeometry(QRect(890, 80, 21, 21));
        hsvEdit = new QLineEdit(ColorPickerClass);
        hsvEdit->setObjectName(QString::fromUtf8("hsvEdit"));
        hsvEdit->setGeometry(QRect(930, 50, 91, 20));
        hsvEdit->setReadOnly(true);
        hslEdit = new QLineEdit(ColorPickerClass);
        hslEdit->setObjectName(QString::fromUtf8("hslEdit"));
        hslEdit->setGeometry(QRect(930, 80, 91, 20));
        hslEdit->setReadOnly(true);
        colorSlot_2 = new QSampleLabel(ColorPickerClass);
        colorSlot_2->setObjectName(QString::fromUtf8("colorSlot_2"));
        colorSlot_2->setGeometry(QRect(780, 170, 41, 31));
        colorSlot_2->setAcceptDrops(true);
        colorSlot_2->setFrameShape(QFrame::NoFrame);
        colorSlot_2->setFrameShadow(QFrame::Plain);
        colorSlot_3 = new QSampleLabel(ColorPickerClass);
        colorSlot_3->setObjectName(QString::fromUtf8("colorSlot_3"));
        colorSlot_3->setGeometry(QRect(780, 210, 41, 31));
        colorSlot_3->setAcceptDrops(true);
        colorSlot_3->setFrameShape(QFrame::NoFrame);
        colorSlot_3->setFrameShadow(QFrame::Plain);
        colorSlot_4 = new QSampleLabel(ColorPickerClass);
        colorSlot_4->setObjectName(QString::fromUtf8("colorSlot_4"));
        colorSlot_4->setGeometry(QRect(780, 250, 41, 31));
        colorSlot_4->setAcceptDrops(true);
        colorSlot_4->setFrameShape(QFrame::NoFrame);
        colorSlot_4->setFrameShadow(QFrame::Plain);
        colorSlot_5 = new QSampleLabel(ColorPickerClass);
        colorSlot_5->setObjectName(QString::fromUtf8("colorSlot_5"));
        colorSlot_5->setGeometry(QRect(780, 290, 41, 31));
        colorSlot_5->setAcceptDrops(true);
        colorSlot_5->setFrameShape(QFrame::NoFrame);
        colorSlot_5->setFrameShadow(QFrame::Plain);
        colorSlot_6 = new QSampleLabel(ColorPickerClass);
        colorSlot_6->setObjectName(QString::fromUtf8("colorSlot_6"));
        colorSlot_6->setGeometry(QRect(780, 330, 41, 31));
        colorSlot_6->setAcceptDrops(true);
        colorSlot_6->setFrameShape(QFrame::NoFrame);
        colorSlot_6->setFrameShadow(QFrame::Plain);
        colorSlot_7 = new QSampleLabel(ColorPickerClass);
        colorSlot_7->setObjectName(QString::fromUtf8("colorSlot_7"));
        colorSlot_7->setGeometry(QRect(780, 370, 41, 31));
        colorSlot_7->setAcceptDrops(true);
        colorSlot_7->setFrameShape(QFrame::NoFrame);
        colorSlot_7->setFrameShadow(QFrame::Plain);
        colorSlot_8 = new QSampleLabel(ColorPickerClass);
        colorSlot_8->setObjectName(QString::fromUtf8("colorSlot_8"));
        colorSlot_8->setGeometry(QRect(780, 410, 41, 31));
        colorSlot_8->setAcceptDrops(true);
        colorSlot_8->setFrameShape(QFrame::NoFrame);
        colorSlot_8->setFrameShadow(QFrame::Plain);
        colorSlot_9 = new QSampleLabel(ColorPickerClass);
        colorSlot_9->setObjectName(QString::fromUtf8("colorSlot_9"));
        colorSlot_9->setGeometry(QRect(830, 130, 41, 31));
        colorSlot_9->setAcceptDrops(true);
        colorSlot_9->setFrameShape(QFrame::NoFrame);
        colorSlot_9->setFrameShadow(QFrame::Plain);
        colorSlot_10 = new QSampleLabel(ColorPickerClass);
        colorSlot_10->setObjectName(QString::fromUtf8("colorSlot_10"));
        colorSlot_10->setGeometry(QRect(830, 170, 41, 31));
        colorSlot_10->setAcceptDrops(true);
        colorSlot_10->setFrameShape(QFrame::NoFrame);
        colorSlot_10->setFrameShadow(QFrame::Plain);
        colorSlot_11 = new QSampleLabel(ColorPickerClass);
        colorSlot_11->setObjectName(QString::fromUtf8("colorSlot_11"));
        colorSlot_11->setGeometry(QRect(830, 210, 41, 31));
        colorSlot_11->setAcceptDrops(true);
        colorSlot_11->setFrameShape(QFrame::NoFrame);
        colorSlot_11->setFrameShadow(QFrame::Plain);
        colorSlot_12 = new QSampleLabel(ColorPickerClass);
        colorSlot_12->setObjectName(QString::fromUtf8("colorSlot_12"));
        colorSlot_12->setGeometry(QRect(830, 250, 41, 31));
        colorSlot_12->setAcceptDrops(true);
        colorSlot_12->setFrameShape(QFrame::NoFrame);
        colorSlot_12->setFrameShadow(QFrame::Plain);
        colorSlot_13 = new QSampleLabel(ColorPickerClass);
        colorSlot_13->setObjectName(QString::fromUtf8("colorSlot_13"));
        colorSlot_13->setGeometry(QRect(830, 290, 41, 31));
        colorSlot_13->setAcceptDrops(true);
        colorSlot_13->setFrameShape(QFrame::NoFrame);
        colorSlot_13->setFrameShadow(QFrame::Plain);
        colorSlot_14 = new QSampleLabel(ColorPickerClass);
        colorSlot_14->setObjectName(QString::fromUtf8("colorSlot_14"));
        colorSlot_14->setGeometry(QRect(830, 330, 41, 31));
        colorSlot_14->setAcceptDrops(true);
        colorSlot_14->setFrameShape(QFrame::NoFrame);
        colorSlot_14->setFrameShadow(QFrame::Plain);
        colorSlot_15 = new QSampleLabel(ColorPickerClass);
        colorSlot_15->setObjectName(QString::fromUtf8("colorSlot_15"));
        colorSlot_15->setGeometry(QRect(830, 370, 41, 31));
        colorSlot_15->setAcceptDrops(true);
        colorSlot_15->setFrameShape(QFrame::NoFrame);
        colorSlot_15->setFrameShadow(QFrame::Plain);
        colorSlot_16 = new QSampleLabel(ColorPickerClass);
        colorSlot_16->setObjectName(QString::fromUtf8("colorSlot_16"));
        colorSlot_16->setGeometry(QRect(830, 410, 41, 31));
        colorSlot_16->setAcceptDrops(true);
        colorSlot_16->setFrameShape(QFrame::NoFrame);
        colorSlot_16->setFrameShadow(QFrame::Plain);
        colorSlot_17 = new QSampleLabel(ColorPickerClass);
        colorSlot_17->setObjectName(QString::fromUtf8("colorSlot_17"));
        colorSlot_17->setGeometry(QRect(880, 130, 41, 31));
        colorSlot_17->setAcceptDrops(true);
        colorSlot_17->setFrameShape(QFrame::NoFrame);
        colorSlot_17->setFrameShadow(QFrame::Plain);
        colorSlot_18 = new QSampleLabel(ColorPickerClass);
        colorSlot_18->setObjectName(QString::fromUtf8("colorSlot_18"));
        colorSlot_18->setGeometry(QRect(880, 170, 41, 31));
        colorSlot_18->setAcceptDrops(true);
        colorSlot_18->setFrameShape(QFrame::NoFrame);
        colorSlot_18->setFrameShadow(QFrame::Plain);
        colorSlot_19 = new QSampleLabel(ColorPickerClass);
        colorSlot_19->setObjectName(QString::fromUtf8("colorSlot_19"));
        colorSlot_19->setGeometry(QRect(880, 210, 41, 31));
        colorSlot_19->setAcceptDrops(true);
        colorSlot_19->setFrameShape(QFrame::NoFrame);
        colorSlot_19->setFrameShadow(QFrame::Plain);
        colorSlot_20 = new QSampleLabel(ColorPickerClass);
        colorSlot_20->setObjectName(QString::fromUtf8("colorSlot_20"));
        colorSlot_20->setGeometry(QRect(880, 250, 41, 31));
        colorSlot_20->setAcceptDrops(true);
        colorSlot_20->setFrameShape(QFrame::NoFrame);
        colorSlot_20->setFrameShadow(QFrame::Plain);
        colorSlot_21 = new QSampleLabel(ColorPickerClass);
        colorSlot_21->setObjectName(QString::fromUtf8("colorSlot_21"));
        colorSlot_21->setGeometry(QRect(880, 290, 41, 31));
        colorSlot_21->setAcceptDrops(true);
        colorSlot_21->setFrameShape(QFrame::NoFrame);
        colorSlot_21->setFrameShadow(QFrame::Plain);
        colorSlot_22 = new QSampleLabel(ColorPickerClass);
        colorSlot_22->setObjectName(QString::fromUtf8("colorSlot_22"));
        colorSlot_22->setGeometry(QRect(880, 330, 41, 31));
        colorSlot_22->setAcceptDrops(true);
        colorSlot_22->setFrameShape(QFrame::NoFrame);
        colorSlot_22->setFrameShadow(QFrame::Plain);
        colorSlot_23 = new QSampleLabel(ColorPickerClass);
        colorSlot_23->setObjectName(QString::fromUtf8("colorSlot_23"));
        colorSlot_23->setGeometry(QRect(880, 370, 41, 31));
        colorSlot_23->setAcceptDrops(true);
        colorSlot_23->setFrameShape(QFrame::NoFrame);
        colorSlot_23->setFrameShadow(QFrame::Plain);
        colorSlot_24 = new QSampleLabel(ColorPickerClass);
        colorSlot_24->setObjectName(QString::fromUtf8("colorSlot_24"));
        colorSlot_24->setGeometry(QRect(880, 410, 41, 31));
        colorSlot_24->setAcceptDrops(true);
        colorSlot_24->setFrameShape(QFrame::NoFrame);
        colorSlot_24->setFrameShadow(QFrame::Plain);
        colorSlot_25 = new QSampleLabel(ColorPickerClass);
        colorSlot_25->setObjectName(QString::fromUtf8("colorSlot_25"));
        colorSlot_25->setGeometry(QRect(930, 130, 41, 31));
        colorSlot_25->setAcceptDrops(true);
        colorSlot_25->setFrameShape(QFrame::NoFrame);
        colorSlot_25->setFrameShadow(QFrame::Plain);
        colorSlot_26 = new QSampleLabel(ColorPickerClass);
        colorSlot_26->setObjectName(QString::fromUtf8("colorSlot_26"));
        colorSlot_26->setGeometry(QRect(930, 170, 41, 31));
        colorSlot_26->setAcceptDrops(true);
        colorSlot_26->setFrameShape(QFrame::NoFrame);
        colorSlot_26->setFrameShadow(QFrame::Plain);
        colorSlot_27 = new QSampleLabel(ColorPickerClass);
        colorSlot_27->setObjectName(QString::fromUtf8("colorSlot_27"));
        colorSlot_27->setGeometry(QRect(930, 210, 41, 31));
        colorSlot_27->setAcceptDrops(true);
        colorSlot_27->setFrameShape(QFrame::NoFrame);
        colorSlot_27->setFrameShadow(QFrame::Plain);
        colorSlot_28 = new QSampleLabel(ColorPickerClass);
        colorSlot_28->setObjectName(QString::fromUtf8("colorSlot_28"));
        colorSlot_28->setGeometry(QRect(930, 250, 41, 31));
        colorSlot_28->setAcceptDrops(true);
        colorSlot_28->setFrameShape(QFrame::NoFrame);
        colorSlot_28->setFrameShadow(QFrame::Plain);
        colorSlot_29 = new QSampleLabel(ColorPickerClass);
        colorSlot_29->setObjectName(QString::fromUtf8("colorSlot_29"));
        colorSlot_29->setGeometry(QRect(930, 290, 41, 31));
        colorSlot_29->setAcceptDrops(true);
        colorSlot_29->setFrameShape(QFrame::NoFrame);
        colorSlot_29->setFrameShadow(QFrame::Plain);
        colorSlot_30 = new QSampleLabel(ColorPickerClass);
        colorSlot_30->setObjectName(QString::fromUtf8("colorSlot_30"));
        colorSlot_30->setGeometry(QRect(930, 330, 41, 31));
        colorSlot_30->setAcceptDrops(true);
        colorSlot_30->setFrameShape(QFrame::NoFrame);
        colorSlot_30->setFrameShadow(QFrame::Plain);
        colorSlot_31 = new QSampleLabel(ColorPickerClass);
        colorSlot_31->setObjectName(QString::fromUtf8("colorSlot_31"));
        colorSlot_31->setGeometry(QRect(930, 370, 41, 31));
        colorSlot_31->setAcceptDrops(true);
        colorSlot_31->setFrameShape(QFrame::NoFrame);
        colorSlot_31->setFrameShadow(QFrame::Plain);
        colorSlot_32 = new QSampleLabel(ColorPickerClass);
        colorSlot_32->setObjectName(QString::fromUtf8("colorSlot_32"));
        colorSlot_32->setGeometry(QRect(930, 410, 41, 31));
        colorSlot_32->setAcceptDrops(true);
        colorSlot_32->setFrameShape(QFrame::NoFrame);
        colorSlot_32->setFrameShadow(QFrame::Plain);
        colorSlot_33 = new QSampleLabel(ColorPickerClass);
        colorSlot_33->setObjectName(QString::fromUtf8("colorSlot_33"));
        colorSlot_33->setGeometry(QRect(980, 130, 41, 31));
        colorSlot_33->setAcceptDrops(true);
        colorSlot_33->setFrameShape(QFrame::NoFrame);
        colorSlot_33->setFrameShadow(QFrame::Plain);
        colorSlot_34 = new QSampleLabel(ColorPickerClass);
        colorSlot_34->setObjectName(QString::fromUtf8("colorSlot_34"));
        colorSlot_34->setGeometry(QRect(980, 170, 41, 31));
        colorSlot_34->setAcceptDrops(true);
        colorSlot_34->setFrameShape(QFrame::NoFrame);
        colorSlot_34->setFrameShadow(QFrame::Plain);
        colorSlot_35 = new QSampleLabel(ColorPickerClass);
        colorSlot_35->setObjectName(QString::fromUtf8("colorSlot_35"));
        colorSlot_35->setGeometry(QRect(980, 210, 41, 31));
        colorSlot_35->setAcceptDrops(true);
        colorSlot_35->setFrameShape(QFrame::NoFrame);
        colorSlot_35->setFrameShadow(QFrame::Plain);
        colorSlot_36 = new QSampleLabel(ColorPickerClass);
        colorSlot_36->setObjectName(QString::fromUtf8("colorSlot_36"));
        colorSlot_36->setGeometry(QRect(980, 250, 41, 31));
        colorSlot_36->setAcceptDrops(true);
        colorSlot_36->setFrameShape(QFrame::NoFrame);
        colorSlot_36->setFrameShadow(QFrame::Plain);
        colorSlot_37 = new QSampleLabel(ColorPickerClass);
        colorSlot_37->setObjectName(QString::fromUtf8("colorSlot_37"));
        colorSlot_37->setGeometry(QRect(980, 290, 41, 31));
        colorSlot_37->setAcceptDrops(true);
        colorSlot_37->setFrameShape(QFrame::NoFrame);
        colorSlot_37->setFrameShadow(QFrame::Plain);
        colorSlot_38 = new QSampleLabel(ColorPickerClass);
        colorSlot_38->setObjectName(QString::fromUtf8("colorSlot_38"));
        colorSlot_38->setGeometry(QRect(980, 330, 41, 31));
        colorSlot_38->setAcceptDrops(true);
        colorSlot_38->setFrameShape(QFrame::NoFrame);
        colorSlot_38->setFrameShadow(QFrame::Plain);
        colorSlot_39 = new QSampleLabel(ColorPickerClass);
        colorSlot_39->setObjectName(QString::fromUtf8("colorSlot_39"));
        colorSlot_39->setGeometry(QRect(980, 370, 41, 31));
        colorSlot_39->setAcceptDrops(true);
        colorSlot_39->setFrameShape(QFrame::NoFrame);
        colorSlot_39->setFrameShadow(QFrame::Plain);
        colorSlot_40 = new QSampleLabel(ColorPickerClass);
        colorSlot_40->setObjectName(QString::fromUtf8("colorSlot_40"));
        colorSlot_40->setGeometry(QRect(980, 410, 41, 31));
        colorSlot_40->setAcceptDrops(true);
        colorSlot_40->setFrameShape(QFrame::NoFrame);
        colorSlot_40->setFrameShadow(QFrame::Plain);
        saturationSlider = new QSlider(ColorPickerClass);
        saturationSlider->setObjectName(QString::fromUtf8("saturationSlider"));
        saturationSlider->setGeometry(QRect(740, 10, 22, 471));
        saturationSlider->setMaximum(24);
        saturationSlider->setSingleStep(1);
        saturationSlider->setValue(12);
        saturationSlider->setOrientation(Qt::Vertical);
        saturationSlider->setTickPosition(QSlider::TicksBothSides);
        saturationSlider->setTickInterval(3);
        clearButton = new QPushButton(ColorPickerClass);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));
        clearButton->setGeometry(QRect(780, 460, 241, 23));

        retranslateUi(ColorPickerClass);

        QMetaObject::connectSlotsByName(ColorPickerClass);
    } // setupUi

    void retranslateUi(QWidget *ColorPickerClass)
    {
        ColorPickerClass->setWindowTitle(QApplication::translate("ColorPickerClass", "ColorPicker", 0, QApplication::UnicodeUTF8));
        imageLabel->setText(QString());
        som1DLabel->setText(QString());
        som2DLabel->setText(QString());
        computeButton->setText(QApplication::translate("ColorPickerClass", "Compute", 0, QApplication::UnicodeUTF8));
        openButton->setText(QApplication::translate("ColorPickerClass", "Open", 0, QApplication::UnicodeUTF8));
        pasteButton->setText(QApplication::translate("ColorPickerClass", "Paste", 0, QApplication::UnicodeUTF8));
        colorLabel->setText(QString());
        colorSlot_1->setText(QString());
        rgbLabel->setText(QApplication::translate("ColorPickerClass", "RGB", 0, QApplication::UnicodeUTF8));
        hsvLabel->setText(QApplication::translate("ColorPickerClass", "HSV", 0, QApplication::UnicodeUTF8));
        hslLabel->setText(QApplication::translate("ColorPickerClass", "HSL", 0, QApplication::UnicodeUTF8));
        colorSlot_2->setText(QString());
        colorSlot_3->setText(QString());
        colorSlot_4->setText(QString());
        colorSlot_5->setText(QString());
        colorSlot_6->setText(QString());
        colorSlot_7->setText(QString());
        colorSlot_8->setText(QString());
        colorSlot_9->setText(QString());
        colorSlot_10->setText(QString());
        colorSlot_11->setText(QString());
        colorSlot_12->setText(QString());
        colorSlot_13->setText(QString());
        colorSlot_14->setText(QString());
        colorSlot_15->setText(QString());
        colorSlot_16->setText(QString());
        colorSlot_17->setText(QString());
        colorSlot_18->setText(QString());
        colorSlot_19->setText(QString());
        colorSlot_20->setText(QString());
        colorSlot_21->setText(QString());
        colorSlot_22->setText(QString());
        colorSlot_23->setText(QString());
        colorSlot_24->setText(QString());
        colorSlot_25->setText(QString());
        colorSlot_26->setText(QString());
        colorSlot_27->setText(QString());
        colorSlot_28->setText(QString());
        colorSlot_29->setText(QString());
        colorSlot_30->setText(QString());
        colorSlot_31->setText(QString());
        colorSlot_32->setText(QString());
        colorSlot_33->setText(QString());
        colorSlot_34->setText(QString());
        colorSlot_35->setText(QString());
        colorSlot_36->setText(QString());
        colorSlot_37->setText(QString());
        colorSlot_38->setText(QString());
        colorSlot_39->setText(QString());
        colorSlot_40->setText(QString());
        clearButton->setText(QApplication::translate("ColorPickerClass", "Clear", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ColorPickerClass: public Ui_ColorPickerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLORPICKER_H
