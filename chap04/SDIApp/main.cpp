#include <QApplication>
#include "sdiwindow.h"

int main(int argc, char** argv)
{
    QApplication a(argc, argv);


    SdiWindow *mainWindow = new SdiWindow();

    mainWindow->show();

    return a.exec();
}
