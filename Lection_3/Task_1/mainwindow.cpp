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

    if (key >= ALPHABET_SIZE)
        return;

    for(int character = 0; character < input.length(); ++character)
    {
            if((input[character] < 'A' || input[character] > 'Z') && (input[character] < 'a' || input[character] > 'z'))
                continue;

            unsigned int shift = input[character].isUpper() ? ASCII_UPPERCASE : ASCII_LOWERCASE;

            input[character] = QChar((ALPHABET_SIZE + int(input[character].toLatin1() - shift - (key * (decrypt ? 1 : -1))) % ALPHABET_SIZE) % ALPHABET_SIZE + shift);
    }

    ui->editOutput->setText(input);
}
