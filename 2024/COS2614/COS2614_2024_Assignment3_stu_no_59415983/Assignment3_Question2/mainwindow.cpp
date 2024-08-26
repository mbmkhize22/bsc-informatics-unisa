#include "MainWindow.h"

MainWindow::MainWindow(Gate* gate, QWidget* parent)
    : QMainWindow(parent), gate(gate) {

    QWidget* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    display = new QLineEdit(this);
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignCenter);

    resultLabel = new QLabel(this);
    resultLabel->setAlignment(Qt::AlignCenter);

    QGridLayout* layout = new QGridLayout;

    layout->addWidget(new QLabel("Gate: " + QString::fromStdString(gate->getDescription()), this), 0, 0, 1, 3);


    layout->addWidget(display, 1, 0, 1, 3);
    layout->addWidget(resultLabel, 2, 0, 1, 3);

    QStringList buttons = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "#"};
    int pos = 0;
    for (const QString& text : buttons) {
        QPushButton* button = new QPushButton(text, this);
        connect(button, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
        layout->addWidget(button, 3 + pos / 3, pos % 3);
        pos++;
    }

    centralWidget->setLayout(layout);
    setWindowTitle("Access Control");
}

MainWindow::~MainWindow() {}

void MainWindow::onButtonClicked() {
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (!button) return;

    QString buttonText = button->text();

    if (buttonText == "#") {
        verifyPassword();
    } else {
        currentInput += buttonText;
        display->setText(currentInput);
    }
}

void MainWindow::verifyPassword() {
    if (gate->checkPassword(currentInput.toStdString())) {
        resultLabel->setText("Access Granted");
    } else {
        resultLabel->setText("Access Denied");
    }
    currentInput.clear();
    display->clear();
}
