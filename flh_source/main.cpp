#include "flh.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    flh w;
    w.show();

    return a.exec();
}
