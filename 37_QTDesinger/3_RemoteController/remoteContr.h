//
// Created by kurchin_iu on 19.05.2026.
//

#ifndef INC_1_CALCUI_CALCMAINWINDOW_H
#define INC_1_CALCUI_CALCMAINWINDOW_H

#include <QLCDNumber>
#include <QMainWindow>

class RemoteMainWindow : public QMainWindow {
    Q_OBJECT

public:
    QLCDNumber* lcdNumber = nullptr;
    QLCDNumber* lcdNumber_2 = nullptr;

    RemoteMainWindow(QWidget* parent = nullptr): QMainWindow(parent) {}

public slots:
    void Num1 () {
        if (lcdNumber) {
            int current = lcdNumber->value();
            if (isTyping && current < 100 && current > 0) { lcdNumber->display(current * 10 + 1); }
            else { lcdNumber->display(1); isTyping = true; }
        }
    }
    void Num2 () {
        if (lcdNumber) {
            int current = lcdNumber->value();
            if (isTyping && current < 100 && current > 0) { lcdNumber->display(current * 10 + 2); }
            else { lcdNumber->display(2); isTyping = true; }
        }
    }
    void Num3 () {
        if (lcdNumber) {
            int current = lcdNumber->value();
            if (isTyping && current < 100 && current > 0) { lcdNumber->display(current * 10 + 3); }
            else { lcdNumber->display(3); isTyping = true; }
        }
    }
    void Num4 () {
        if (lcdNumber) {
            int current = lcdNumber->value();
            if (isTyping && current < 100 && current > 0) { lcdNumber->display(current * 10 + 4); }
            else { lcdNumber->display(4); isTyping = true; }
        }
    }
    void Num5 () {
        if (lcdNumber) {
            int current = lcdNumber->value();
            if (isTyping && current < 100 && current > 0) { lcdNumber->display(current * 10 + 5); }
            else { lcdNumber->display(5); isTyping = true; }
        }
    }
    void Num6 () {
        if (lcdNumber) {
            int current = lcdNumber->value();
            if (isTyping && current < 100 && current > 0) { lcdNumber->display(current * 10 + 6); }
            else { lcdNumber->display(6); isTyping = true; }
        }
    }
    void Num7 () {
        if (lcdNumber) {
            int current = lcdNumber->value();
            if (isTyping && current < 100 && current > 0) { lcdNumber->display(current * 10 + 7); }
            else { lcdNumber->display(7); isTyping = true; }
        }
    }
    void Num8 () {
        if (lcdNumber) {
            int current = lcdNumber->value();
            if (isTyping && current < 100 && current > 0) { lcdNumber->display(current * 10 + 8); }
            else { lcdNumber->display(8); isTyping = true; }
        }
    }
    void Num9 () {
        if (lcdNumber) {
            int current = lcdNumber->value();
            if (isTyping && current < 100 && current > 0) { lcdNumber->display(current * 10 + 9); }
            else { lcdNumber->display(9); isTyping = true; }
        }
    }
    void Num0 () {
        if (lcdNumber) {
            int current = lcdNumber->value();
            if (isTyping && current < 100 && current > 0) { lcdNumber->display(current * 10 + 0); }
            else { lcdNumber->display(0); isTyping = true; }
        }
    }

    void PowerButton () {};
    void MuteButton () {
        if (lcdNumber_2) {
            muted = !muted;
            if (muted) {
                lcdNumber_2->display(0);
            } else {
                lcdNumber_2->display(currentVolume);
            }
        }
    };
    void VlmPlus () {
        if (lcdNumber_2) {
            muted = false;
            if (currentVolume < 100) {
                currentVolume += 5;
            }
            lcdNumber_2->display(currentVolume);
        }
    };

    void VlmSubstr ()  {
        if (lcdNumber_2) {
            muted = false;
            if (currentVolume > 0) {
                currentVolume -= 5;
            }
            lcdNumber_2->display(currentVolume);
        }
    };

    void ChnlPlus() {
        if(lcdNumber) {
            isTyping = false;
            int current = lcdNumber->value();
            if (current >= 999) { lcdNumber->display(1); }
            else { lcdNumber->display(current + 1); }
        }
    }

    void ChnlSubstr () {
        if (lcdNumber) {
            isTyping = false;
            int current = lcdNumber->value();
            if (current <= 1) { lcdNumber->display(999); }
            else { lcdNumber->display(current - 1); }
        }
    }

private:
    bool isTyping = false;
    int currentVolume = 30;
    bool muted = false;
};

#endif //INC_1_CALCUI_CALCMAINWINDOW_H