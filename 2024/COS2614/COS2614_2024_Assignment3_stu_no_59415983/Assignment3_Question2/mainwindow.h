#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include "Gate.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(Gate* gate, QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void onButtonClicked();

private:
    Gate* gate;
    QLineEdit* display;
    QLabel* resultLabel;
    QString currentInput;

    void createLayout();
    void verifyPassword();
};

#endif
