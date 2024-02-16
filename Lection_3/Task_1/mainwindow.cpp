#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_editInput_textChanged()
{
    Crypt();
}

void MainWindow::on_editKey_textChanged()
{
    Crypt();
}

void MainWindow::on_buttonEncrypt_clicked()
{
    Crypt();
}

void MainWindow::on_buttonDecrypt_clicked()
{
    Crypt();
}

void MainWindow::Crypt()
{
    QString input = ui->editInput->toPlainText();
    unsigned int key = ui->editKey->text().toInt();
    bool decrypt = ui->buttonDecrypt->isChecked();

    if (!decrypt && !ui->buttonEncrypt->isChecked())
        return;

    if (key > 26)
        return;

    for(int character = 0; character < input.length(); ++character)
    {
            if((input[character] < 'A' || input[character] > 'Z') && (input[character] < 'a' || input[character] > 'z'))
                continue;

            if (decrypt)
            {
                if (input[character].isUpper())
                    input[character] = QChar((26 + int(input[character].toLatin1() - ASCII_UPPERCASE - key) % 26) % 26 + ASCII_UPPERCASE);
                else
                    input[character] = QChar((26 + int(input[character].toLatin1() - ASCII_LOWERCASE - key) % 26) % 26 + ASCII_LOWERCASE);
            }
            else
            {
                if (input[character].isUpper())
                    input[character] = QChar(int(input[character].toLatin1() - ASCII_UPPERCASE + key) % 26 + ASCII_UPPERCASE);
                else
                    input[character] = QChar(int(input[character].toLatin1() - ASCII_LOWERCASE + key) % 26 + ASCII_LOWERCASE);
            }
    }

    ui->editOutput->setText(input);
}
