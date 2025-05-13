#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFile>
#include <QIODevice>
#include <QMainWindow>
#include <QString>
#include <QTextStream>
#include <QVector>
#include "addform.h"
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
    AddForm* addForm;

    QString StructToString(const Car& car);

   private slots:
    void Add();
    void AddToTextFile(Car car);
    void AddToBinFile(Car car);
    void ClearText();
    void ClearBin();
    void ShowText();
    void ShowBin();
};
#endif	// MAINWINDOW_H
