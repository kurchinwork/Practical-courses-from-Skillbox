/********************************************************************************
** Form generated from reading UI file 'masknum.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MASKNUM_H
#define UI_MASKNUM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MaskNum
{
public:
    QWidget *centralWidget;
    QLineEdit *lineEdit;
    QLabel *label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MaskNum)
    {
        if (MaskNum->objectName().isEmpty())
            MaskNum->setObjectName(QStringLiteral("MaskNum"));
        MaskNum->resize(792, 540);
        centralWidget = new QWidget(MaskNum);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(10, 10, 771, 21));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(360, 230, 47, 13));
        MaskNum->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MaskNum);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 792, 21));
        MaskNum->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MaskNum);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MaskNum->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MaskNum);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MaskNum->setStatusBar(statusBar);

        retranslateUi(MaskNum);

        QMetaObject::connectSlotsByName(MaskNum);
    } // setupUi

    void retranslateUi(QMainWindow *MaskNum)
    {
        MaskNum->setWindowTitle(QApplication::translate("MaskNum", "MaskNum", 0));
        label->setText(QApplication::translate("MaskNum", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class MaskNum: public Ui_MaskNum {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MASKNUM_H
