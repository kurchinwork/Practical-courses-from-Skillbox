#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString startHtml = ui->textEdit->toPlainText();
    ui->webView->setHtml(startHtml);

    connect(ui->textEdit, &QTextEdit::textChanged, [this]() {
        QString htmlCode = ui->textEdit->toPlainText();

        ui->webView->setHtml(htmlCode);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
