#include <QApplication>
#include <QPushButton>
#include "./ui_calc_1.h"
#include "calcMainWindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    CalcMainWindow window(nullptr);
    Ui::MainWindow calc;
    calc.setupUi(&window);
    window.lineEdit = calc.lineEdit;
    window.lineEdit_2 = calc.lineEdit_2;
    window.lineEdit_3 = calc.lineEdit_3;

    calc.lineEdit->installEventFilter(&window);
    calc.lineEdit_2->installEventFilter(&window);

    window.show();
    return QApplication::exec();
}