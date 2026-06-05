#ifndef BLUREDITOR_H
#define BLUREDITOR_H

#include <QMainWindow>
#include <QImage>
#include <QGraphicsScene>
#include <QFutureWatcher>

namespace Ui {
class BlurEditor;
}

class BlurEditor : public QMainWindow
{
    Q_OBJECT

public:
    explicit BlurEditor(QWidget *parent = 0);
    ~BlurEditor();

private slots:
    void on_pushButton_clicked();
    void on_horizontalSlider_valueChanged(int value);
    void onBlurFinished();

private:
    Ui::BlurEditor *ui;

    QImage originalImage;
    QGraphicsScene* scene;
    QFutureWatcher<QImage> watcher;
};

#endif // BLUREDITOR_H
