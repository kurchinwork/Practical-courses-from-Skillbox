#include "blureditor.h"
#include "ui_blureditor.h"
#include <QFileDialog>
#include <QtConcurrent/QtConcurrent>
#include <QGraphicsBlurEffect>
#include <QGraphicsPixmapItem>
#include <QPainter>

QImage blurImage(QImage source, int blurRadius) {
    if (source.isNull() || blurRadius <= 0) {
        return source;
    }

    QGraphicsScene tempScene;
    QGraphicsPixmapItem item;

    item.setPixmap(QPixmap::fromImage(source));

    QGraphicsBlurEffect blur;
    blur.setBlurRadius(blurRadius);
    blur.setBlurHints(QGraphicsBlurEffect::PerformanceHint);

    item.setGraphicsEffect(&blur);
    tempScene.addItem(&item);

    QImage result (source.size(), QImage::Format_ARGB32);
    result.fill(Qt::transparent);
    QPainter painter(&result);
    tempScene.render(&painter, QRectF(), QRectF(0,0, source.width(), source.height()));

    return result;
}

BlurEditor::BlurEditor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BlurEditor)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    ui->horizontalSlider->setRange(0,20);
    ui->horizontalSlider->setValue(0);

    connect(&watcher, &QFutureWatcher<QImage>::finished, this, &BlurEditor::onBlurFinished);
}

BlurEditor::~BlurEditor()
{
    delete ui;
}

void BlurEditor::on_pushButton_clicked() {
    QString filePath = QFileDialog::getOpenFileName(this,
        tr("Открыть изображение"), "", tr("Изображения (*.png *.jpg *.jpeg *.bmp)"));

    if (!filePath.isEmpty()) {
        originalImage.load(filePath);

        ui->horizontalSlider->setValue(0);
        scene->clear();
        scene->addPixmap(QPixmap::fromImage(originalImage));
        ui->graphicsView->setSceneRect(originalImage.rect());
    }
}

// Слот слайдера
void BlurEditor::on_horizontalSlider_valueChanged(int value) {
    if (originalImage.isNull()) return;

    if (watcher.isRunning()) {
        watcher.cancel();
    }

    // Запуск функции blurImage в отдельном потоке через QtConcurrent
    QFuture<QImage> future = QtConcurrent::run(blurImage, originalImage, value);
    watcher.setFuture(future);
}

// слот, вызываемый  по окончании размытия
void BlurEditor::onBlurFinished() {
    if (watcher.isCanceled()) return;

    // результат из потока
    QImage blurredImage = watcher.result();

    // обновление картинки
    scene->clear();
    scene->addPixmap(QPixmap::fromImage(blurredImage));
}
