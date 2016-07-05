#ifndef SDIWINDOW_H
#define SDIWINDOW_H

#include <QMainWindow>

class QTextEdit;


class SdiWindow : public QMainWindow
{
    Q_OBJECT

private:
    QTextEdit* docWidget;
    QAction    *newAction
             , *cutAction
             , *copyAction
             , *pasteAction
             , *aboutAction
             , *aboutQtAction
             , *closeAction
             , *exitAction;

public:
    explicit SdiWindow(QWidget *parent = 0);

signals:

private slots:
    void fileNew();
    void helpAbout();

public slots:
    void createActions();
    void createMenus();
    void createToolbars();
    void closeEvent(QCloseEvent *event);
    bool isSafeToClose();



};

#endif // SDIWINDOW_H
