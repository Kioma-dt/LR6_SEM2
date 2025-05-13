#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    addForm = new AddForm();

    connect(ui->buttonAdd, &QPushButton::clicked, this, &MainWindow::Add);
    connect(ui->buttonShowText, &QPushButton::clicked, this,
            &MainWindow::ShowText);
    connect(ui->buttonShowBin, &QPushButton::clicked, this,
            &MainWindow::ShowBin);
    connect(ui->buttonClearText, &QPushButton::clicked, this,
            &MainWindow::ClearText);
    connect(ui->buttonClearBin, &QPushButton::clicked, this,
            &MainWindow::ClearBin);

    connect(addForm, &AddForm::AddStructToTextFile, this,
            &MainWindow::AddToTextFile);
    connect(addForm, &AddForm::AddStructToBinFile, this,
            &MainWindow::AddToBinFile);

    this->ClearBin();
    this->ClearText();
}

MainWindow::~MainWindow() {
    delete ui;
}

QString MainWindow::StructToString(const Car& car) {
    QString tempText;
    tempText = QString("%1|%2|%3|%4|%5|")
                   .arg(car.numberOfCylinders)
                   .arg(car.engineVolume)
                   .arg(car.tireMark)
                   .arg(car.manualTransmission)
                   .arg(car.number);


    for (int i = 0; i < 4; i++) {
        tempText += QString::number(car.yearsOfMaintenance[i]);
        tempText += ' ';
    }

    return tempText;
}

void MainWindow::Add() {
    addForm->setWindowModality(Qt::ApplicationModal);
    addForm->show();
}

void MainWindow::AddToTextFile(Car car) {
    QFile file("AvramenkoLab20_2.txt");

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text |
                   QIODevice::Append)) {
        QMessageBox::warning(this, "Add Problem", "Can't Open File");
        return;
    }

    QTextStream out(&file);

    out << StructToString(car);
    out << "\n";

    file.close();
}

void MainWindow::AddToBinFile(Car car) {
    QFile file("AvramenkoLab20_3.bin");

    if (!file.open(QIODevice::WriteOnly | QIODevice::Append)) {
        QMessageBox::warning(this, "Add Problem", "Can't Open File");
        return;
    }

    file.write(reinterpret_cast<char*>(&car.numberOfCylinders),
               sizeof(car.numberOfCylinders));
    file.write(reinterpret_cast<char*>(&car.engineVolume),
               sizeof(car.engineVolume));
    file.write(reinterpret_cast<char*>(&car.tireMark), sizeof(car.tireMark));
    file.write(reinterpret_cast<char*>(&car.manualTransmission),
               sizeof(car.manualTransmission));
    file.write(reinterpret_cast<char*>(&car.number), sizeof(car.number));
    file.write(reinterpret_cast<char*>(&car.yearsOfMaintenance),
               sizeof(car.yearsOfMaintenance));

    file.close();
}

void MainWindow::ClearText() {
    QFile file("AvramenkoLab20_2.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        QMessageBox::warning(this, "Clear Problem", "Can't Open File");
        return;
    }
    this->ShowText();
    file.close();
}

void MainWindow::ClearBin() {
    QFile file("AvramenkoLab20_3.bin");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        QMessageBox::warning(this, "Clear Problem", "Can't Open File");
        return;
    }
    this->ShowBin();
    file.close();
}

void MainWindow::ShowText() {
    QFile file("AvramenkoLab20_2.txt");


    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, "Text Problem", "Can't Open File");
        return;
    }

    QTextStream in(&file);

    ui->textFile->clear();
    ui->textFile->setFontPointSize(16);
    while (!in.atEnd()) {
        ui->textFile->append(in.readLine());
    }

    file.close();
}

void MainWindow::ShowBin() {
    QFile file("AvramenkoLab20_3.bin");


    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, "Bin Problem", "Can't Open File");
        return;
    }

    ui->textBin->clear();
    ui->textBin->setFontPointSize(16);

    while (!file.atEnd()) {
        Car car;
        file.read(reinterpret_cast<char*>(&car.numberOfCylinders),
                  sizeof(car.numberOfCylinders));
        file.read(reinterpret_cast<char*>(&car.engineVolume),
                  sizeof(car.engineVolume));
        file.read(reinterpret_cast<char*>(&car.tireMark), sizeof(car.tireMark));
        file.read(reinterpret_cast<char*>(&car.manualTransmission),
                  sizeof(car.manualTransmission));
        file.read(reinterpret_cast<char*>(&car.number), sizeof(car.number));
        file.read(reinterpret_cast<char*>(&car.yearsOfMaintenance),
                  sizeof(car.yearsOfMaintenance));

        ui->textBin->append(this->StructToString(car));
    }

    file.close();
}
