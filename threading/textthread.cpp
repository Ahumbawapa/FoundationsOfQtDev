#include "textthread.h"
#include <QDebug>
#include <QMutexLocker>

//global variable used to stop execution of all threads
bool stopThreads = false;
QMutex mutex;

TextThread::TextThread(const QString &text, TextDevice *device)
    :QThread()//important to call base class constructor for valid initialization
{
    m_text = text;
    m_textDevice = device;
}

TextThread::~TextThread()
{
    delete m_textDevice;
}

void TextThread::run()
{
    //send text to debug output until stopThreads is true
    while(!stopThreads)
    {
        this->m_textDevice->write(m_text);
        sleep(1);
    }
}
