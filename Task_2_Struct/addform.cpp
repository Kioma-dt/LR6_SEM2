#include "addform.h"
#include "ui_addform.h"

AddForm::AddForm(QWidget* parent) : QWidget(parent), ui(new Ui::AddForm) {
    ui->setupUi(this);

    connect(ui->buttonText, &QPushButton::clicked, this,
            &AddForm::ToTextFileSlot);
    connect(ui->buttonBin, &QPushButton::clicked, this,
            &AddForm::ToBinFileSlot);
}

AddForm::~AddForm() {
    delete ui;
}

Car AddForm::CreateStructure() {
    bool ok_cyl = false, ok_vol = false;

    unsigned int numberOfCylinders = ui->textCylinders->text().toUInt(&ok_cyl);


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

    Car car{
        .numberOfCylinders = numberOfCylinders,
        .engineVolume = engineVolume,
        .tireMark = tireMark,
        .manualTransmission = manualTransmission,
        .number = {carNumber[0], carNumber[1], carNumber[2], carNumber[3],
                   carNumber[4], carNumber[5], carNumber[6], carNumber[7]},
        .yearsOfMaintenance = {yearsOfMaintenance[0], yearsOfMaintenance[1],
                               yearsOfMaintenance[2], yearsOfMaintenance[3]}};

    return car;
}

void AddForm::ToTextFileSlot() {
    try {
        Car car = this->CreateStructure();
        this->close();
        emit AddStructToTextFile(car);
    }


    catch (const std::runtime_error& ex) {
        QMessageBox::warning(this, "Can't Add Struct", ex.what());
        this->close();
    }
}

void AddForm::ToBinFileSlot() {
    try {
        Car car = this->CreateStructure();
        this->close();
        emit AddStructToBinFile(car);
    }


    catch (const std::runtime_error& ex) {
        QMessageBox::warning(this, "Can't Add Struct", ex.what());
        this->close();
    }
}
