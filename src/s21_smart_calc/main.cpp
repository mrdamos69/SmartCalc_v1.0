#include "s21_smart_calc_cpp.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    s21_smart_calc_cpp w;
    w.show();
    return a.exec();
}
