/********************************************************************************
** Form generated from reading UI file 'colorpicker.ui'
**
** Created: Sun Feb 19 23:59:35 2017
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
#include <QtGui/QPushButton>
#include <QtGui/QWidget>
#include <colorspaceview.h>

QT_BEGIN_NAMESPACE

class Ui_ColorPickerClass
{
public:
    QLabel *imageLabel;
    QLabel *som1DLabel;
    QLabel *som2DLabel;
    QPushButton *computeButton;
    QPushButton *openButton;
    ColorSpaceView *glWidget;
    QPushButton *pasteButton;

    void setupUi(QWidget *ColorPickerClass)
    {
        if (ColorPickerClass->objectName().isEmpty())
            ColorPickerClass->setObjectName(QString::fromUtf8("ColorPickerClass"));
        ColorPickerClass->resize(747, 501);
        imageLabel = new QLabel(ColorPickerClass);
        imageLabel->setObjectName(QString::fromUtf8("imageLabel"));
        imageLabel->setGeometry(QRect(20, 10, 201, 171));
        imageLabel->setFrameShape(QFrame::Box);
        som1DLabel = new QLabel(ColorPickerClass);
        som1DLabel->setObjectName(QString::fromUtf8("som1DLabel"));
        som1DLabel->setGeometry(QRect(20, 250, 200, 16));
        som1DLabel->setFrameShape(QFrame::Box);
        som2DLabel = new QLabel(ColorPickerClass);
        som2DLabel->setObjectName(QString::fromUtf8("som2DLabel"));
        som2DLabel->setGeometry(QRect(20, 280, 200, 200));
        som2DLabel->setFrameShape(QFrame::Box);
        computeButton = new QPushButton(ColorPickerClass);
        computeButton->setObjectName(QString::fromUtf8("computeButton"));
        computeButton->setGeometry(QRect(20, 220, 201, 23));
        openButton = new QPushButton(ColorPickerClass);
        openButton->setObjectName(QString::fromUtf8("openButton"));
        openButton->setGeometry(QRect(20, 190, 91, 23));
        glWidget = new ColorSpaceView(ColorPickerClass);
        glWidget->setObjectName(QString::fromUtf8("glWidget"));
        glWidget->setGeometry(QRect(240, 10, 480, 480));
        pasteButton = new QPushButton(ColorPickerClass);
        pasteButton->setObjectName(QString::fromUtf8("pasteButton"));
        pasteButton->setGeometry(QRect(134, 190, 91, 23));

        retranslateUi(ColorPickerClass);

        QMetaObject::connectSlotsByName(ColorPickerClass);
    } // setupUi

    void retranslateUi(QWidget *ColorPickerClass)
    {
        ColorPickerClass->setWindowTitle(QApplication::translate("ColorPickerClass", "ColorPicker", 0, QApplication::UnicodeUTF8));
        imageLabel->setText(QString());
        som1DLabel->setText(QString());
        som2DLabel->setText(QApplication::translate("ColorPickerClass", "TextLabel", 0, QApplication::UnicodeUTF8));
        computeButton->setText(QApplication::translate("ColorPickerClass", "Compute", 0, QApplication::UnicodeUTF8));
        openButton->setText(QApplication::translate("ColorPickerClass", "Open", 0, QApplication::UnicodeUTF8));
        pasteButton->setText(QApplication::translate("ColorPickerClass", "Paste", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ColorPickerClass: public Ui_ColorPickerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLORPICKER_H
