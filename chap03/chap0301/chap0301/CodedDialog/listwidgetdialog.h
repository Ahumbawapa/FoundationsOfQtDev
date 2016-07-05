#ifndef LISTWIDGETDIALOG_H
#define LISTWIDGETDIALOG_H

#include <QDialog>

namespace Ui {
class ListWidgetDialog;
}

class ListWidgetDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ListWidgetDialog(QWidget *parent = 0);
    ~ListWidgetDialog();


public slots:
    void moveLeft();
    void moveRight();

private:
    Ui::ListWidgetDialog *ui;
};

#endif // LISTWIDGETDIALOG_H
