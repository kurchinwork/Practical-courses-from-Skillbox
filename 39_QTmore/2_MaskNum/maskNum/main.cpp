#include "masknum.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MaskNum w;
    w.show();

    return a.exec();
}
