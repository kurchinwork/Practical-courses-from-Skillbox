#ifndef MASKNUM_H
#define MASKNUM_H

#include <QMainWindow>

namespace Ui {
class MaskNum;
}

class MaskNum : public QMainWindow
{
    Q_OBJECT

public:
    explicit MaskNum(QWidget *parent = 0);
    ~MaskNum();
private slots:
    void setOkLabel();
    void setNonOkLabel();


private:
    Ui::MaskNum *ui;
};

#endif // MASKNUM_H
