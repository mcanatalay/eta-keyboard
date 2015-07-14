#include <QtGui/QApplication>
#include "etaKeyboard.h"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    etaKeyboard etakeyboard;
    etakeyboard.show();
    return app.exec();
}
