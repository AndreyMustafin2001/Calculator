#include "speedwagon.h"

MyCalculator::MyCalculator(QWidget *parent)
    : QWidget{parent}
{
    QPushButton *btn[14];
    QChar bts[14] = {
        '0','1','2','3','4','5','6','7','8','9','+','-','/','*'
    };

    for(int i=0;i<14;i++)
    {
        btn[i] = new QPushButton(bts[i],this);
        btn[i]->setFixedSize(63,44);
        if(i<10)
            btn[i]->setStyleSheet("background-color: orange;");
        else
            btn[i]->setStyleSheet("background-color: grey;");
    }

    QPushButton *clearBtn = new QPushButton("clear",this);
    clearBtn->setFixedSize(63,44);
    clearBtn->setStyleSheet("background-color: red;");

    QPushButton *eqBtn = new QPushButton("=",this);
    eqBtn->setFixedSize(63,44);
    eqBtn->setStyleSheet("background-color: green;");

    QGridLayout *grid = new QGridLayout(this);
    lineEdit = new QLineEdit(this);
    lineEdit->setFixedSize(255,44);
    grid->addWidget(lineEdit,0,0,1,5);

    QFont font("Arial", 11);
    lineEdit->setFont(font);

    grid->addWidget(btn[0],4,0);
    grid->addWidget(btn[1],3,0);   grid->addWidget(btn[4],2,0);  grid->addWidget(btn[7],1,0);
    grid->addWidget(btn[2],3,1);   grid->addWidget(btn[5],2,1);  grid->addWidget(btn[8],1,1);
    grid->addWidget(btn[3],3,2);   grid->addWidget(btn[6],2,2);  grid->addWidget(btn[9],1,2);

    grid->addWidget(btn[10],1,4);  grid->addWidget(eqBtn,4,2);
    grid->addWidget(btn[11],2,4);  grid->addWidget(clearBtn,4,1);
    grid->addWidget(btn[13],3,4);
    grid->addWidget(btn[12],4,4);

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
bool isOperator(const QChar& ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int applyOperation(int a,int b,const QChar& op)
{
    if (op == '+')
        return a + b;
    else if (op == '-')
        return a - b;
    else if (op == '*')
        return a * b;
    else if (op == '/')
        return a / b;
    else
        return 0;
}
int evaluateExpression(const QString& expression)
{
    QStack<int> operands;
    QStack<QChar> operators;

    int i = 0;
    while (i < expression.length())
    {
        if (expression[i].isDigit() || (expression[i] == '-' && (i == 0 || isOperator(expression[i - 1]))))
        {
            int num = 0;
            int sign = 1;
            if (expression[i] == '-')
            {
                sign = -1;
                i++; // Skip the "-" symbol
            }
            while (i < expression.length() && expression[i].isDigit()) {
                num = num * 10 + expression[i].digitValue();
                i++;
            }
            operands.push(num * sign);
        }
        else if (isOperator(expression[i]))
        {
            while (!operators.isEmpty() && ((expression[i] != '*' && expression[i] != '/') || (operators.top() == '*' || operators.top() == '/')))
            {
                int b = operands.pop();
                int a = operands.pop();
                operands.push(applyOperation(a, b, operators.pop()));
            }
            operators.push(expression[i]);
            i++;
        }
        else
        {
            i++; // Skip other characters
        }
    }

    while (!operators.isEmpty())
    {
        int b = operands.pop();
        int a = operands.pop();
        operands.push(applyOperation(a, b, operators.pop()));
    }

    return operands.pop();
}
void MyCalculator::OnEq()
{
    QString str = lineEdit->text();
    int result = evaluateExpression(str.simplified());
    lineEdit->setText(QString::number(result));
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
    if(lastChar.isDigit())
        return true;
    else
        return false;
}


