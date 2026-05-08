#include <QApplication>
#include <QSlider>
#include <QSpinBox>
#include <QLabel>
#include <QWidget>
#include <QVBoxLayout>
#include <QPixmap>

int main(int argc, char *argv[])
{
    QApplication App(argc, argv);

    QWidget *window = new QWidget();
    window->setWindowTitle("RGB Spinner");

    auto *slider = new QSlider(Qt::Horizontal);
    auto *spinbox = new QSpinBox();
    auto *imageLabel = new QLabel();

    slider->setRange(0, 100);
    spinbox->setRange(0, 100);
    imageLabel->setAlignment(Qt::AlignCenter);
    imageLabel->setFixedSize(200,200);

    QObject::connect(slider, &QSlider::valueChanged, [imageLabel, spinbox](int value) {

        spinbox->setValue(value);

        if(value <= 33) {
            imageLabel->setPixmap(QPixmap(":/Red.png").scaled(200,200, Qt::KeepAspectRatio));
        } else if (value > 33 && value <= 66) {
            imageLabel->setPixmap(QPixmap(":/Green.png").scaled(200,200, Qt::KeepAspectRatio));
        } else {
            imageLabel->setPixmap(QPixmap(":/Blue.png").scaled(200,200, Qt::KeepAspectRatio));
        }
});

    QObject::connect(slider, SIGNAL(valueChanged(int)), spinbox, SLOT(setValue(int)));
    QObject::connect(spinbox, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));

    QVBoxLayout *layout = new QVBoxLayout(window);
    layout->addWidget(imageLabel);
    layout->addWidget(slider);
    layout->addWidget(spinbox);

    window->show();

    return App.exec();
}
