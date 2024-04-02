#include "window.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Window w;
    if(!w.initZmlCore())
    {
        QMessageBox::warning(nullptr,"Error","Load Dll Failed.\n",QMessageBox::StandardButton::Ok);
        return 0;
    }
    w.show();
    return a.exec();
}
