//main01.cpp
//executable for first thread example

#include "textthread.h"
#include <QApplication>
#include <QMessageBox>


extern bool stopThreads;

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    //create two Thread - Objects
    TextThread  tt1("TextThread01")
               ,tt2("TextThread02");


    //start the created threads
    tt1.start();
    tt2.start();

    QMessageBox::information(0, "Threading", "Close me to stop!");

    stopThreads = true;

    //wait until the threads have stopped
    tt1.wait();
    tt2.wait();

    return 0;

}
