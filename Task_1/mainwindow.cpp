#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    connect(ui->buttonPrintStrcut, &QPushButton::clicked, this,
            &MainWindow::GetUserStructure);

    this->PrintStrctures();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::PrintStrctures() {
    QFont font;
    font.setPointSize(16);

    Car carInit{.numberOfCylinders = 4,
                .engineVolume = 3.6,
                .tireMark = 'S',
                .manualTransmission = false,
                .number = {'3', '4', '5', '6', 'A', 'K', '7', '\0'},
                .yearsOfMaintenance = {2008, 2012, 2016, 2020}};

    ui->textInit->setText("\n" + this->StructToString(carInit));
    ui->textInit->setFont(font);

    Car carField;
    carField.numberOfCylinders = 8;
    carField.engineVolume = 12;
    carField.tireMark = 'H';
    carField.manualTransmission = false;
    carField.number[0] = '8';
    carField.number[1] = '8';
    carField.number[2] = '0';
    carField.number[3] = '0';
    carField.number[4] = 'C';
    carField.number[5] = 'S';
    carField.number[6] = '3';
    carField.number[7] = '\0';
    carField.yearsOfMaintenance[0] = 2006;
    carField.yearsOfMaintenance[1] = 2010;
    carField.yearsOfMaintenance[2] = 2014;
    carField.yearsOfMaintenance[3] = 2018;

    ui->textFileds->setText("\n" + this->StructToString(carField));
    ui->textFileds->setFont(font);

    Car* carPointer = new Car;
    carPointer->numberOfCylinders = 12;
    carPointer->engineVolume = 5.6;
    carPointer->tireMark = 'S';
    carPointer->manualTransmission = true;
    carPointer->number[0] = '6';
    carPointer->number[1] = '4';
    carPointer->number[2] = '4';
    carPointer->number[3] = '6';
    carPointer->number[4] = 'M';
    carPointer->number[5] = 'A';
    carPointer->number[6] = '1';
    carPointer->number[7] = '\0';
    carPointer->yearsOfMaintenance[0] = 2003;
    carPointer->yearsOfMaintenance[1] = 2005;
    carPointer->yearsOfMaintenance[2] = 2040;
    carPointer->yearsOfMaintenance[3] = 2100;

    QString tempText;
    tempText = QString("%1 | %2 | %3 | %4 | %5 | ")
                   .arg(carPointer->numberOfCylinders)
                   .arg(carPointer->engineVolume)
                   .arg(carPointer->tireMark)
                   .arg(carPointer->manualTransmission)
                   .arg(carPointer->number);


    for (int i = 0; i < 4; i++) {
        tempText += QString::number(carPointer->yearsOfMaintenance[i]);
        tempText += ' ';
    }
    ui->textPointer->setText("\n" + tempText);
    ui->textPointer->setFont(font);

    Car carSimple;
    Car& refCar = carSimple;
    refCar.numberOfCylinders = 12;
    refCar.engineVolume = 0.33;
    refCar.tireMark = 'M';
    refCar.manualTransmission = true;
    refCar.number[0] = '7';
    refCar.number[1] = '7';
    refCar.number[2] = '7';
    refCar.number[3] = '7';
    refCar.number[4] = 'A';
    refCar.number[5] = 'Z';
    refCar.number[6] = '7';
    refCar.number[7] = '\0';
    refCar.yearsOfMaintenance[0] = 0;
    refCar.yearsOfMaintenance[1] = 0;
    refCar.yearsOfMaintenance[2] = 0;
    refCar.yearsOfMaintenance[3] = 0;

    tempText = QString("%1 | %2 | %3 | %4 | %5 | ")
                   .arg(refCar.numberOfCylinders)
                   .arg(refCar.engineVolume)
                   .arg(refCar.tireMark)
                   .arg(refCar.manualTransmission)
                   .arg(refCar.number);


    for (int i = 0; i < 4; i++) {
        tempText += QString::number(refCar.yearsOfMaintenance[i]);
        tempText += ' ';
    }
    ui->textRef->setText("\n" + tempText);
    ui->textRef->setFont(font);
}

void MainWindow::PrintUserStruct(const Car& userStruct) {
    QFont font;
    font.setPointSize(16);

    ui->textUser->setText("\n" + this->StructToString(userStruct));
    ui->textUser->setFont(font);
}

QString MainWindow::StructToString(const Car& structure) {
    QString tempText;
    tempText = QString("%1 | %2 | %3 | %4 | %5 | ")
                   .arg(structure.numberOfCylinders)
                   .arg(structure.engineVolume)
                   .arg(structure.tireMark)
                   .arg(structure.manualTransmission)
                   .arg(structure.number);


    for (int i = 0; i < 4; i++) {
        tempText += QString::number(structure.yearsOfMaintenance[i]);
        tempText += ' ';
    }

    return tempText;
}

void MainWindow::GetUserStructure() {
    try {
        bool ok_cyl = false, ok_vol = false;

        unsigned int numberOfCylinders =
            ui->textCylinders->text().toUInt(&ok_cyl);


        if (!ok_cyl) {
            throw std::runtime_error("Wrong Number of Cylinders Format");
        }

        double engineVolume = ui->textVolume->text().toDouble(&ok_vol);


        if (!ok_cyl || engineVolume <= 0) {
            throw std::runtime_error("Wrong Engine Volume Format");
        }

        char tireMark = ui->comboBoxTieMark->currentText()[0].unicode();
        bool manualTransmission = ui->radioButtonTransmission->isChecked();

        QString tempCarNumber = ui->textNumber->text();
        char carNumber[8];
        if (tempCarNumber.size() != 7) {
            throw std::runtime_error("Wrong Number Format");
        }


        for (int i = 0; i < 7; i++) {
            if (!tempCarNumber[i].isLetterOrNumber()) {
                throw std::runtime_error("Wrong Number Format");
            }
            carNumber[i] = tempCarNumber[i].unicode();
        }
        carNumber[7] = '\0';

        QStringList tempYears = ui->textYears->text().split(QChar(' '));
        unsigned int yearsOfMaintenance[4];
        if (tempYears.size() != 4) {
            throw std::runtime_error("Wrong Years Format");
        }


        for (int i = 0; i < 4; i++) {
            bool ok = false;
            yearsOfMaintenance[i] = tempYears[i].toUInt(&ok);

            if (!ok) {
                throw std::runtime_error("Wrong Years Format");
            }
        }

        Car userCar{
            .numberOfCylinders = numberOfCylinders,
            .engineVolume = engineVolume,
            .tireMark = tireMark,
            .manualTransmission = manualTransmission,
            .number = {carNumber[0], carNumber[1], carNumber[2], carNumber[3],
                       carNumber[4], carNumber[5], carNumber[6], carNumber[7]},
            .yearsOfMaintenance = {yearsOfMaintenance[0], yearsOfMaintenance[1],
                                   yearsOfMaintenance[2],
                                   yearsOfMaintenance[3]}};

        this->PrintUserStruct(userCar);
    }


    catch (const std::runtime_error& ex) {
        QMessageBox::warning(this, "User Struct", ex.what());
    }
}
