#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "car.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

   public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

   private:
    Ui::MainWindow* ui;
    void PrintStrctures();
    void PrintUserStruct(const Car& userStruct);
    QString StructToString(const Car& structure);

   private slots:
    void GetUserStructure();
};
#endif	// MAINWINDOW_H
