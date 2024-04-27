#include <iostream>
#include <speedwagon.h>

int main(int argc,char** argv)
{
    QApplication app(argc,argv);
    MyCalculator a;
    a.resize(100,100);
    a.setWindowTitle("Calculator");
    a.show();
    return app.exec();
}
