#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define ASCII_UPPERCASE 65
#define ASCII_LOWERCASE 97

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_editInput_textChanged();

    void on_editKey_textChanged();

    void on_buttonEncrypt_clicked();

    void on_buttonDecrypt_clicked();

private:
    Ui::MainWindow *ui;
    void Crypt();
};
#endif // MAINWINDOW_H
