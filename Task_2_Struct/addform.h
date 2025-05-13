#ifndef ADDFORM_H
#define ADDFORM_H

#include <QMessageBox>
#include <QPushButton>
#include <QWidget>
#include "car.h"

namespace Ui {
class AddForm;
}

class AddForm : public QWidget {
    Q_OBJECT

   public:
    explicit AddForm(QWidget* parent = nullptr);
    ~AddForm();

   private:
    Ui::AddForm* ui;

    Car CreateStructure();

   private slots:
    void ToTextFileSlot();
    void ToBinFileSlot();

   signals:
    void AddStructToTextFile(Car car);
    void AddStructToBinFile(Car car);
};

#endif	// ADDFORM_H
