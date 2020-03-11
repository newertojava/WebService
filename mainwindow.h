#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include "qtsoap.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QLabel *m_pQQLabel;
    QLabel *m_pStateLabel;
    QLineEdit *m_pQQLineEdit;
    QLineEdit *m_pStateLineEdit;
    QPushButton *m_pSubmitButton;
    QtSoapHttpTransport *m_pHttp;

public slots:
    void onSubmit();
    void onResponse(const QtSoapMessage&);
};

#endif // MAINWINDOW_H
