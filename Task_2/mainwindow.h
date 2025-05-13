#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFile>
#include <QMainWindow>
#include <QMessageBox>
#include <QString>
#include <QTextStream>
#include <QTimer>
#include <QVector>
#include <fstream>

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

    QVector<float> array;

    QString ReadAndWriteParagraph(QString paragraph);

   private slots:
    void CheckParagraphSlot();
    void AddToArraySlot();
    void ClearArraySlot();
    void SaveArraySlot();
    void ShowArraySlot();
    void AddSentenceSlot();
    void ShowTextSlot();
    void ClearTextSlot();
};
#endif	// MAINWINDOW_H
