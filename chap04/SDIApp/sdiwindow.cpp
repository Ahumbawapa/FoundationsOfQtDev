#include "sdiwindow.h"
#include <QMainWindow>
#include <QString>
#include <QTextEdit>
#include <QStatusBar>
#include <QAction>
#include <QApplication>
#include <QtGui>

SdiWindow::SdiWindow(QWidget *parent) : QMainWindow(parent)
{
    //let QT takes care of memory for main window
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowTitle( tr("%1[*] - %2").arg(tr("unnamed"))
                                    .arg(tr("SDI")));

    docWidget = new QTextEdit(this);
    //fill the entire main window
    setCentralWidget(docWidget);

    //signal will be emited from the document of the QTextedit
    //connect modified status of text editor's document
    //to windowModified property of the main window
    connect(docWidget->document(), SIGNAL(modificationChanged(bool)),
            this                 , SLOT(setWindowModified(bool)));

    createActions();
    createMenus();
    createToolbars();

    statusBar()->showMessage("Done");

}

void SdiWindow::createActions()
{
    newAction = new QAction( QIcon(":/images/new.png"),  tr("&New"),  this);
    newAction->setShortcut(tr("Ctrl+N"));
    newAction->setStatusTip(tr("Create a new document"));
    connect( newAction, SIGNAL(triggered()), this, SLOT(fileNew()));

    closeAction = new QAction(tr("&Close"), this);
    closeAction->setShortcut(tr("Ctrl+w"));
    closeAction->setStatusTip(tr("Close this document"));
    connect( closeAction, SIGNAL(triggered()), this, SLOT(close()));

    exitAction = new QAction(tr("E&xit"), this);
    exitAction->setShortcut(tr("Ctrl+Q"));
    exitAction->setStatusTip(tr("Quit the application"));
    connect( exitAction, SIGNAL(triggered()), qApp, SLOT(closeAllWindows()));

    cutAction = new QAction( QIcon(":/images/cut.png"),  tr("Cu&t"),  this);
    cutAction->setShortcut(tr("Ctrl+X"));
    cutAction->setStatusTip(tr("Cut"));
    cutAction->setEnabled(false);
    connect( docWidget, SIGNAL(copyAvailable(bool)) , cutAction, SLOT(setEnabled(bool)));
    connect( cutAction, SIGNAL(triggered())         , docWidget, SLOT(cut()));

    copyAction = new QAction(QIcon(":/images/copy.png"), tr("&Copy"), this);
    copyAction->setShortcut(tr("Ctrl+C"));
    copyAction->setStatusTip(tr("Copy"));
    copyAction->setEnabled(false);
    connect( docWidget, SIGNAL(copyAvailable(bool)), copyAction, SLOT(setEnabled(bool)));
    connect( copyAction, SIGNAL(triggered(bool)), docWidget, SLOT(copy()));

    pasteAction = new QAction(QIcon(":/images/paste.png"), tr("&Paste"), this);
    pasteAction->setShortcut(tr("Ctrl+V"));
    pasteAction->setStatusTip(tr("Paste"));
    connect( pasteAction, SIGNAL(triggered(bool)), docWidget, SLOT(paste()));

    aboutAction = new QAction(tr("&About"), this);
    aboutAction->setStatusTip(tr("About this application"));
    connect( aboutAction, SIGNAL(triggered(bool)), this, SLOT(helpAbout()));

    aboutQtAction = new QAction(tr("About &Qt"), this);
    aboutQtAction->setStatusTip(tr("About the Qt toolkit"));

    connect( aboutQtAction, SIGNAL(triggered()),
             qApp,          SLOT(aboutQt()));
}

void SdiWindow::createMenus()
{
    QMenu *menu;

    menu = menuBar()->addMenu(tr("&File"));
    menu->addAction(newAction);
    menu->addAction(closeAction);
    menu->addSeparator();
    menu->addAction(exitAction);

    menu = menuBar()->addMenu(tr("&Edit"));
    menu->addAction(cutAction);
    menu->addAction(copyAction);
    menu->addAction(pasteAction);

    menu = menuBar()->addMenu(tr("&Help"));
    menu->addAction(aboutQtAction);
    menu->addAction(aboutAction);
}


void SdiWindow::createToolbars()
{
    QToolBar *toolBar;
    toolBar = addToolBar(tr("File"));
    toolBar->addAction(newAction);

    toolBar = addToolBar(tr("Edit"));
    toolBar->addAction(cutAction);
    toolBar->addAction(copyAction);
    toolBar->addAction(pasteAction);
}

void SdiWindow::fileNew()
{
    (new SdiWindow())->show();
}

void SdiWindow::helpAbout()
{
   QMessageBox::about( this, tr("About SDI"), tr("A single document interface application."));
}

void SdiWindow::closeEvent(QCloseEvent *event)
{
    if(isSafeToClose())
        event->accept();
    else
        event->ignore();
}

bool SdiWindow::isSafeToClose()
{
    if(isWindowModified())
    {
        switch( QMessageBox::warning(   this
                                      , tr("SDI")
                                      , tr("The document has unsaved changes.\n"
                                           "Do you want to save it before it is closed?")
                                      , QMessageBox::Discard | QMessageBox::Cancel
                                    )

              )
        {
            case QMessageBox::Cancel:
                return false;
            default:
                return true;
        }
    }

    return true;
}
