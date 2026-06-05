#include <QApplication>
#include <QPushButton>
#include <QPainter>
#include <QPaintEvent>
#include <iostream>
#include <QTimer>
#include <QMediaPlayer>

class ImageButton : public QPushButton {
    Q_OBJECT
public:
    ImageButton() = default;
    ImageButton(QWidget *parent);

    void paintEvent(QPaintEvent *) override;
    QSize sizeHint() const override;

    QSize minimumSizeHint() const override;
    void keyPressEvent(QKeyEvent *) override;

public slots:
    void setUp();
    void setDown();

private:
    QPixmap mCurrentButtonPixmap;
    QPixmap mCurrentDownPixmap;
    QPixmap mCurrentUpPixmap;

    bool isDown = false;
};

ImageButton::ImageButton(QWidget *parent) {
    setParent(parent);
    setToolTip("Жмякай");
    QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);


    mCurrentUpPixmap = QPixmap("..\\sources\\Down.png");
    mCurrentDownPixmap = QPixmap("..\\sources\\Up.png");

    mCurrentButtonPixmap = mCurrentUpPixmap;

    setGeometry(mCurrentButtonPixmap.rect());

    connect(this, &QPushButton::clicked, this, &ImageButton::setDown);
}

void ImageButton::paintEvent(QPaintEvent *e) {
    QPainter p(this);
    p.drawPixmap(e->rect(), mCurrentButtonPixmap);
}

QSize ImageButton::sizeHint() const {
    return QSize(100, 100);
}

QSize ImageButton::minimumSizeHint() const {
    return sizeHint();
}

void ImageButton::keyPressEvent(QKeyEvent *e) {
    setDown();
}

void ImageButton::setDown() {
    mCurrentButtonPixmap = mCurrentDownPixmap;
    update();

    QTimer::singleShot (100, this, &ImageButton::setUp);
}

void ImageButton::setUp() {
    mCurrentButtonPixmap = mCurrentUpPixmap;
    update();
}

int main(int argc, char *argv[]) {
    QApplication MainApp(argc, argv);
    ImageButton redButton(nullptr);
    redButton.setFixedSize(100, 100);
    redButton.move(1000, 400);

    QMediaPlayer *player = new QMediaPlayer (&MainApp);

    player->setMedia(QUrl::fromLocalFile("..\\sources\\Uh-Oh-Mistake.wav"));

    QObject::connect(&redButton, &QPushButton::clicked, player, [player]() {
        std::cout << "Click" << std::endl;

    if (player->state() == QMediaPlayer::PlayingState) {
        player->stop();
    }
        player->play();
});

    redButton.show();
    return MainApp.exec();
}

#include "main.moc"