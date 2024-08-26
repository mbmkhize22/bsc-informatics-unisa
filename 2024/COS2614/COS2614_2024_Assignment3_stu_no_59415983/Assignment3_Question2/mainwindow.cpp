#include "MainWindow.h"
#include <QVBoxLayout>

MainWindow::MainWindow(Gate* gate, QWidget* parent)
    : QMainWindow(parent), gate(gate) {

    QWidget* centralWidget = new QWidget(this);
    QVBoxLayout* layout = new QVBoxLayout(centralWidget);

    descriptionLabel = new QLabel(QString::fromStdString(gate->getDescription()), this);
    layout->addWidget(descriptionLabel);

    passwordInput = new QLineEdit(this);
    passwordInput->setEchoMode(QLineEdit::Password);
    layout->addWidget(passwordInput);

    QPushButton* enterButton = new QPushButton("Enter", this);
    layout->addWidget(enterButton);

    resultLabel = new QLabel(this);
    layout->addWidget(resultLabel);

    setCentralWidget(centralWidget);

    connect(enterButton, &QPushButton::clicked, this, &MainWindow::onEnterClicked);
}

MainWindow::~MainWindow() {}

void MainWindow::onEnterClicked() {
    std::string enteredPassword = passwordInput->text().toStdString();

    if (gate->checkPassword(enteredPassword)) {
        resultLabel->setText("Access Granted");
    } else {
        resultLabel->setText("Access Denied");
    }
}
