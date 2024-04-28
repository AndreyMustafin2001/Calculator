#pragma once
#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QString>
#include <QDebug>
#include <QStack>

class MyCalculator : public QWidget
{
    Q_OBJECT
public:
    MyCalculator(QWidget *parent = 0);
private slots:
    void Clear();
    void OnClick(QChar c);
    bool lastCheck();
    void addSymbol(QChar c);
    void OnEq();
private:
    QLineEdit *lineEdit;

};


