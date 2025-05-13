#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    connect(ui->textParagraphInput, &QTextEdit::textChanged, this,
            &MainWindow::CheckParagraphSlot);
    connect(ui->buttonAddArray, &QPushButton::clicked, this,
            &MainWindow::AddToArraySlot);
    connect(ui->buttonClearArray, &QPushButton::clicked, this,
            &MainWindow::ClearArraySlot);
    connect(ui->buttonSaveArray, &QPushButton::clicked, this,
            &MainWindow::SaveArraySlot);
    connect(ui->buttonShowArray, &QPushButton::clicked, this,
            &MainWindow::ShowArraySlot);
    connect(ui->textSentence, &QTextEdit::textChanged, this,
            &MainWindow::AddSentenceSlot);
    connect(ui->buttonShowText, &QPushButton::clicked, this,
            &MainWindow::ShowTextSlot);
    connect(ui->buttonClearText, &QPushButton::clicked, this,
            &MainWindow::ClearTextSlot);
}

MainWindow::~MainWindow() {
    delete ui;
}

QString MainWindow::ReadAndWriteParagraph(QString paragraph) {
    try {
        std::ofstream fileWrite("AvramenkoLab20.txt");

        if (!fileWrite.is_open()) {
            throw std::runtime_error("Can't Write To File");
        }


        for (int i = 0; i < paragraph.size(); i++) {
            fileWrite.put(paragraph[i].unicode());
        }

        fileWrite.close();

        std::ifstream fileRead("AvramenkoLab20.txt");

        char ch;
        QString userParagraph = "";

        while (fileRead.get(ch)) {
            userParagraph.append(ch);
        }

        fileRead.close();

        return userParagraph;
    }


    catch (const std::runtime_error& ex) {
        QMessageBox::warning(this, "Paragraph Problem", ex.what());
        return "";
    }
}

void MainWindow::CheckParagraphSlot() {
    if (ui->textParagraphInput->toPlainText().endsWith(QChar('\n'))) {
        QString userParagraph =
            this->ReadAndWriteParagraph(ui->textParagraphInput->toPlainText());
        ui->textParagraphInput->clear();
        ui->textParagraphOutput->setFontPointSize(16);
        ui->textParagraphOutput->setText(userParagraph);
    }
}

void MainWindow::AddToArraySlot() {
    bool ok = false;

    float temp_value = ui->textArrayElement->text().toFloat(&ok);
    ui->textArrayElement->clear();


    if (!ok) {
        QMessageBox::warning(this, "Array Problem", "Wrong Element Format");
        return;
    }

    array.push_back(temp_value);
}

void MainWindow::ClearArraySlot() {
    array.clear();
    this->SaveArraySlot();
    this->ShowArraySlot();
}

void MainWindow::SaveArraySlot() {
    QFile file("AvramenkoLab20_0.txt");

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Array Problem", "Can't Open File");
        return;
    }

    QTextStream out(&file);


    for (int i = 0; i < array.size(); i++) {
        out << array[i];
        if (i != array.size() - 1) {
            out << '_';
        }
    }

    file.close();
}

void MainWindow::ShowArraySlot() {
    QFile file("AvramenkoLab20_0.txt");

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Array Problem", "Can't Open File");
        return;
    }

    QTextStream in(&file);

    ui->textArrayFromFile->clear();
    QString temp_string = "";
    while (!in.atEnd()) {
        float temp_value;
        in >> temp_value;

        if (in.status() != QTextStream::Ok) {
            QMessageBox::warning(this, "Array Problem", "Can't Read File");
            return;
        }

        temp_string += QString::number(temp_value);

        if (!in.atEnd()) {
            in.read(1);
            temp_string += " ";
        }
    }
    ui->textArrayFromFile->setFontPointSize(16);
    ui->textArrayFromFile->setText(temp_string);

    file.close();
}

void MainWindow::AddSentenceSlot() {
    if (ui->textSentence->toPlainText().endsWith(QChar('\n'))) {
        QFile file("AvramenkoLab20_1.txt");


        if (!file.open(QIODevice::WriteOnly | QIODevice::Text |
                       QIODevice::Append)) {
            QMessageBox::warning(this, "Sentance Problem",
                                 "Can't Add Sentence");
            return;
        }

        QTextStream out(&file);
        out << ui->textSentence->toPlainText();
        ui->textSentence->clear();

        file.close();
    }
}

void MainWindow::ShowTextSlot() {
    QFile file("AvramenkoLab20_1.txt");


    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, "Sentance Problem", "Can't Open File");
        return;
    }

    QTextStream in(&file);

    ui->textFull->clear();
    ui->textFull->setFontPointSize(16);
    while (!in.atEnd()) {
        ui->textFull->append(in.readLine());
    }

    file.close();
}

void MainWindow::ClearTextSlot() {
    QFile file("AvramenkoLab20_1.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        QMessageBox::warning(this, "Sentance Problem", "Can't Open File");
        return;
    }
    this->ShowTextSlot();
    file.close();
}
