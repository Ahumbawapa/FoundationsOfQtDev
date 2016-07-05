#include "codeddialog.h"
#include "buttondialog.h"
#include "listwidgetdialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CodedDialog w;
    //w.show();

    ButtonDialog b;
    //b.show();

    ListWidgetDialog lwd;
    lwd.show();

    return a.exec();
}
