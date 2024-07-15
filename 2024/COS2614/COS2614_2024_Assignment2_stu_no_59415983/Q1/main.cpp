#include "mainwindow.h"

#include <QApplication>
#include <QInputDialog>
#include <QMessageBox>
#include <QString>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString inputString;
    if (argc > 1) {
        inputString = argv[1];
    } else {
        bool ok;
        inputString = QInputDialog::getText(nullptr, "Input", "Enter a string:", QLineEdit::Normal, "", &ok);
        if (!ok) {
            return 0; // If the user cancels the dialog, exit the program
        }
    }

    int length = inputString.length();

    QString message = QString("Input string: %1\nLength: %2").arg(inputString).arg(length);
    QMessageBox::information(nullptr, "String Info", message);

    return 0;
}
