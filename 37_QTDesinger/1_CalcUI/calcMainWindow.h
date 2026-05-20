//
// Created by kurchin_iu on 14.05.2026.
//

#ifndef INC_1_CALCUI_CALCMAINWINDOW_H
#define INC_1_CALCUI_CALCMAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/QLineEdit>
#include "./ui_calc_1.h"

class CalcMainWindow : public QMainWindow {
    Q_OBJECT
public:

    QLineEdit* lineEdit = nullptr;
    QLineEdit* lineEdit_2 = nullptr;
    QLineEdit* lineEdit_3 = nullptr;

    QLineEdit* lastActiveLineEdit = nullptr; //переменная для хранения указателя на поле которое было использовано в последний раз

    CalcMainWindow(QWidget* parent = nullptr): QMainWindow(parent) {}

    //метод захвата кликов по полям ввода
    bool eventFilter(QObject *obj, QEvent *event) override {
        if (event->type() == QEvent::FocusIn) {
            if (obj == lineEdit) lastActiveLineEdit = lineEdit;
            if (obj == lineEdit_2) lastActiveLineEdit = lineEdit_2;
        }
        return QMainWindow::eventFilter(obj, event);
    }


    QLineEdit* getActiveLineEdit() {
        // указатель на первое поле при первом старте
        if (!lastActiveLineEdit) {
            lastActiveLineEdit = lineEdit;
        }
        return lastActiveLineEdit;
    }

public slots:
    void Add1() { QLineEdit* active = getActiveLineEdit(); if(active) active->insert("1"); }
    void Add2() { QLineEdit* active = getActiveLineEdit(); if(active) active->insert("2"); }
    void Add3() { QLineEdit* active = getActiveLineEdit(); if(active) active->insert("3"); }
    void Add4() { QLineEdit* active = getActiveLineEdit(); if(active) active->insert("4"); }
    void Add5() { QLineEdit* active = getActiveLineEdit(); if(active) active->insert("5"); }
    void Add6() { QLineEdit* active = getActiveLineEdit(); if(active) active->insert("6"); }
    void Add7() { QLineEdit* active = getActiveLineEdit(); if(active) active->insert("7"); }
    void Add8() { QLineEdit* active = getActiveLineEdit(); if(active) active->insert("8"); }
    void Add9() { QLineEdit* active = getActiveLineEdit(); if(active) active->insert("9"); }
    void Add0() { QLineEdit* active = getActiveLineEdit(); if(active) active->insert("0"); }

    void AddPtr() {
        QLineEdit* active = getActiveLineEdit();
        if(active && !active->text().contains('.')) active->insert(".");
    }

    void Clear() {
        if(lineEdit) lineEdit->clear();
        if(lineEdit_2) lineEdit_2->clear();
        if(lineEdit_3) lineEdit_3->clear();
    };

    void ResDiv() {
        if (!lineEdit || !lineEdit_2 || !lineEdit_3) {
            return;
        }
        float num1 = lineEdit->text().toFloat();
        float num2 = lineEdit_2->text().toFloat();

        if (num2 == 0.0f) {
            lineEdit_3->setText("Div 0 is danger");
        } else {
            lineEdit_3->setText(QString::number(num1/num2));
        }
    };

    void ResSum() {
        if (!lineEdit || !lineEdit_2 || !lineEdit_3) {
            return;
        }
        float num1 = lineEdit->text().toFloat();
        float num2 = lineEdit_2->text().toFloat();

        lineEdit_3->setText(QString::number(num1+num2));
    };

    void ResSubst() {
        if (!lineEdit || !lineEdit_2 || !lineEdit_3) {
            return;
        }
        float num1 = lineEdit->text().toFloat();
        float num2 = lineEdit_2->text().toFloat();

        lineEdit_3->setText(QString::number(num1-num2));
    };
    void Multypl() {
        if (!lineEdit || !lineEdit_2 || !lineEdit_3) {
            return;
        }
        float num1 = lineEdit->text().toFloat();
        float num2 = lineEdit_2->text().toFloat();

        lineEdit_3->setText(QString::number(num1*num2));
    };
};

#endif //INC_1_CALCUI_CALCMAINWINDOW_H