#include "speedwagon.h"
#include <QGridLayout>
#include <QLineEdit>
#include <QString>
#include <QDebug>

MyCalculator::MyCalculator(QWidget *parent)
    : QWidget{parent}
{
    QPushButton *btn[14];
    QChar bts[14] =
    {
        '0','1','2','3','4','5','6','7','8','9','+','-','/','*'
    };
    for(int i=0;i<14;i++)
    {
        btn[i] = new QPushButton(bts[i],this);
        btn[i]->setMinimumSize(63,44);
        btn[i]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    }

    QPushButton *clearBtn = new QPushButton("clear",this);
    clearBtn->setMinimumSize(63,44);
    clearBtn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QPushButton *eqBtn = new QPushButton("=",this);
    eqBtn->setMinimumSize(63,44);
    eqBtn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QGridLayout *grid = new QGridLayout(this);

    lineEdit = new QLineEdit(this);
    grid->addWidget(lineEdit,0,0,1,5);
    lineEdit->setMinimumSize(240,44);
    lineEdit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QFont font("Arial", 20);
    lineEdit->setFont(font);

    grid->addWidget(clearBtn,4,1);
    grid->addWidget(btn[0],4,0);

    grid->addWidget(btn[1],3,0);   grid->addWidget(btn[4],2,0);  grid->addWidget(btn[7],1,0);
    grid->addWidget(btn[2],3,1);   grid->addWidget(btn[5],2,1);  grid->addWidget(btn[8],1,1);
    grid->addWidget(btn[3],3,2);   grid->addWidget(btn[6],2,2);  grid->addWidget(btn[9],1,2);

    grid->addWidget(btn[10],1,4);
    grid->addWidget(btn[11],2,4);
    grid->addWidget(btn[13],3,4);
    grid->addWidget(btn[12],4,4);
    grid->addWidget(eqBtn,4,2);

    setLayout(grid);

    connect (clearBtn,&QPushButton::clicked,this,&MyCalculator::Clear);
    connect (eqBtn,&QPushButton::clicked,this,&MyCalculator::OnEq);
    for(int i=0;i<=13;i++)
    {
        connect (btn[i],&QPushButton::clicked,this,std::bind(&MyCalculator::OnClick,this,bts[i]));
    }
}
void MyCalculator::Clear()
{
    QString str = lineEdit->text();
    str.chop(1);
    lineEdit->setText(str);
}
void MyCalculator::OnEq()
{
    qDebug()<<"Hello world";
    QString str = lineEdit->text();
    int i=0;
    int c=0;
    while(str[i].isDigit())
    {
        i++;
    }
    QString str1 = str.mid(0,i);
    QString str2 = str.mid(i+1);
    int a = str1.toInt();
    int b = str2.toInt();
    if(str[i] == '+')c=a+b;
    else if(str[i] == '-')c=a-b;
    else if(str[i] == '/')c=a/b;
    else if(str[i] == '*')c=a*b;
    QString res = QString::number(c);
    qDebug()<<res;
    lineEdit->setText(res);
}
void MyCalculator::addSymbol(QChar c)
{

    if (c.isDigit() || lastCheck() == true)
        lineEdit->setText(lineEdit->text() + c);
    else
    {
        QString str =lineEdit->text();
        if(str.isEmpty())return;
        str.chop(1);
        str = str + c;
        lineEdit->setText(str);
    }
}
void MyCalculator::OnClick(QChar c)
{
    addSymbol(c);
}
bool MyCalculator::lastCheck()
{
    QString str = lineEdit->text();
    if(str.isEmpty())
        return false;
    QChar lastChar = str.at(str.length() - 1);
    if(lastChar.isDigit())return true;
    else
        return false;
}


