#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include "Gate.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(Gate* gate, QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void onEnterClicked();

private:
    Gate* gate;
    QLineEdit* passwordInput;
    QLabel* descriptionLabel;
    QLabel* resultLabel;
};

#endif
