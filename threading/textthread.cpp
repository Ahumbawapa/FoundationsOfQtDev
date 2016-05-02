#include "textthread.h"
#include <QDebug>

//global variable used to stop execution of all threads
bool stopThreads = false;


TextThread::TextThread(const QString &text)
    :QThread()//important to call base class constructor for valid initialization
{
    m_text = text;
}

void TextThread::run()
{
    //send text to debug output until stopThreads is true
    while(!stopThreads)
    {
        qDebug() << m_text;
        sleep(1);
    }
}
