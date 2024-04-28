#include <speedwagon.h>

int main(int argc,char** argv)
{
    QApplication app(argc,argv);
    MyCalculator a;
    a.setFixedSize(270,270);
    a.setWindowTitle("Calculator");
    a.show();
    return app.exec();
}
