#include "masknum.h"
#include "ui_masknum.h"

MaskNum::MaskNum(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MaskNum)
{
    ui->setupUi(this);

    connect(ui->lineEdit, &QLineEdit::textEdited, [this](QString currentText)
    {
        QRegularExpression exp("^\\+\\{11}");
        if (exp.match(currentText).hasMatch())
            setOkLabel();
        else
            setNonOkLabel();
    });
}

MaskNum::~MaskNum()
{
    delete ui;
}

void MaskNum::setOkLabel()
{
    ui->label->setText("All is Okay");
    ui->label->setStyleSheet("QLabel {color : green;}");

}

void MaskNum::setNonOkLabel()
{
    ui->label->setText("That not is okay");
    ui->label->setStyleSheet("QLabel {red;}");

}
