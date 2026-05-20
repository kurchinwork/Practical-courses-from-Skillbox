// Created by kurchin_iu on 19.05.2026.

#include "remoteContr.h"
#include "ui_remote_UI.h"

int main (int argc, char *argv[]) {
    QApplication a(argc, argv);

    RemoteMainWindow* window = new RemoteMainWindow();

    Ui::MainWindow ui;
    ui.setupUi(window);

    window->lcdNumber = ui.lcdNumber;
    window->lcdNumber_2 = ui.lcdNumber_2;

    QObject::connect(ui.pushButton, QPushButton::clicked, window, &RemoteMainWindow::Num1);
    QObject::connect(ui.pushButton_2, QPushButton::clicked, window, &RemoteMainWindow::Num2);
    QObject::connect(ui.pushButton_3, QPushButton::clicked, window, &RemoteMainWindow::Num3);
    QObject::connect(ui.pushButton_6, QPushButton::clicked, window, &RemoteMainWindow::Num4);
    QObject::connect(ui.pushButton_7, QPushButton::clicked, window, &RemoteMainWindow::Num5);
    QObject::connect(ui.pushButton_8, QPushButton::clicked, window, &RemoteMainWindow::Num6);
    QObject::connect(ui.pushButton_9, QPushButton::clicked, window, &RemoteMainWindow::Num7);
    QObject::connect(ui.pushButton_10, QPushButton::clicked, window, &RemoteMainWindow::Num8);
    QObject::connect(ui.pushButton_11, QPushButton::clicked, window, &RemoteMainWindow::Num9);
    QObject::connect(ui.pushButton_12, QPushButton::clicked, window, &RemoteMainWindow::Num0);


    window->show();

    return a.exec();
}
