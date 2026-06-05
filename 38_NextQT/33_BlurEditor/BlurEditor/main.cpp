#include "blureditor.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BlurEditor w;
    w.show();

    return a.exec();
}
