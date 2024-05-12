#include <QApplication>
#include <QInputDialog>
#include <QMessageBox>
#include <QStringList>
#include <QRandomGenerator>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    bool ok;
    QString full_name = QInputDialog::getText(nullptr, "Enter your full name", "Fullname: ", QLineEdit::Normal, " ", &ok);

    if(ok) {
        QStringList name_parts = full_name.split(" ");
        QString first_name = name_parts[0];
        QString surname = name_parts.last();
        QString username;
        QString password;

        if(surname.length() >= 4) {
            username = surname.left(4) + first_name.left(1);
        }else{
            QString full_username = surname + first_name;
            username = full_username.leftJustified(5, '0');
        }

        QString pass_char = full_name.simplified().remove(" ").toLower();

        for(int i =0; i< 5; i++) {
            password += pass_char.at(QRandomGenerator::global()->bounded(pass_char.length()));
        }

        QString message = "Username: " + username + "\nInitial Password: " + password;
        QMessageBox::information(nullptr, "Results", message);
    }
    return app.exec();
}
