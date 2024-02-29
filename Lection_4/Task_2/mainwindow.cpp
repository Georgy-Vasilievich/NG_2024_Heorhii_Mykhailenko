#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "JSONParser.h"
#include "XMLParser.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect (ui->buttonSelectFile, &QPushButton::clicked, this, &MainWindow::SelectFile);
    connect (ui->buttonDumpToFile, &QPushButton::clicked, this, &MainWindow::DumpToFile);
    connect (ui->buttonGet, &QPushButton::clicked, this, &MainWindow::GetKey);
    connect (ui->buttonSet, &QPushButton::clicked, this, &MainWindow::SetKey);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SelectFile()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Open File", QString(), "JSON Files (*.json);;XML Files (*.xml)");
    if (!filePath.isEmpty()) {
        ui->labelMessage->setText(filePath);
        QFileInfo fileInfo(filePath);
        extension = fileInfo.suffix();

        if (extension == "json") {
            parser = new JSONParser();
        } else if (extension == "xml") {
            parser = new XMLParser();
        } else {
            return;
        }

        parser->setFile(filePath);
        ui->buttonDumpToFile->setEnabled(true);
        ui->buttonGet->setEnabled(true);
        ui->buttonSet->setEnabled(true);
    }
}

void MainWindow::DumpToFile()
{
    QString filePath = QFileDialog::getSaveFileName(this, "Open File", QString(), extension == "json" ? "JSON Files (*.json)" : "XML Files (*.xml)");
    if (!filePath.isEmpty()) {
        parser->dumpToFile(filePath);
        ui->labelMessage->setText("Saved!");
    }
}

void MainWindow::GetKey()
{
    ui->editValue->setText(parser->getKey(ui->editKey->text()).toString());
}

void MainWindow::SetKey()
{
    parser->setKey(ui->editKey->text(), QVariant(ui->editValue->text()));
}
