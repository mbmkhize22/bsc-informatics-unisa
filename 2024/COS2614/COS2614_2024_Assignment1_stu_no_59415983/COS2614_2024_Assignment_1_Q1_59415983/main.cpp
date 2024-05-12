// COS2614 2024
// Student no: 59415983

#include <QApplication>
#include <QInputDialog>
#include <QMessageBox>
#include <QStringList>
#include <QString>
#include <QRandomGenerator>
#include <QChar>

QString generateUsername(const QString& fullName) {
    QStringList nameParts = fullName.split(" ");
    QString username;

    if (nameParts.size() >= 2) {
        QString firstInitial = nameParts[0].left(1).toUpper();
        QString middleInitial = (nameParts.size() == 3) ? nameParts[1].left(1).toUpper() : "";
        QString lastInitial = (nameParts.size() == 3) ? "" : nameParts[1].left(1).toUpper();

        QString count = QString::number(fullName.simplified().remove(" ").length());

        // Pad the count with leading zeros to make it 4 digits
        while (count.length() < 4) {
            count.prepend("0");
        }

        username = firstInitial + middleInitial + count;
    }

    return username.leftJustified(6, ' ', true);
}

QString generatePassword(const QString& fullName) {
    QString password;
    QStringList nameParts = fullName.split(" ");

    QString allCharacters;
    for (const QString& namePart : nameParts) {
        allCharacters += namePart;
    }

    for(int i = 0; i < 6; i++) {
        password += allCharacters.at(QRandomGenerator::global()->bounded(allCharacters.length()));
    }

    // Ensure at least one vowel and one consonant in the password
    bool hasVowel = false;
    bool hasConsonant = false;
    for (const QChar& ch : password) {
        if (ch.isLetter()) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                hasVowel = true;
            } else {
                hasConsonant = true;
            }
        }
    }

    if (!hasVowel || !hasConsonant) {
        // If the password doesn't have at least one vowel and one consonant, regenerate it
        return generatePassword(fullName);
    }

    return password.toLower();
}



int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    bool ok;
    QString full_name = QInputDialog::getText(nullptr, "Enter your full name...", "Fullname: ", QLineEdit::Normal, "", &ok);

    if(ok) {
        QStringList name_parts = full_name.split(" ");
        if(name_parts.length() >= 2)
        {

            QString username = generateUsername(full_name);
            QString password = generatePassword(full_name);

            QString message = "uid: " + username + "\nInitial Password: " + password;
            QMessageBox::information(nullptr, "Results", message);
        }
        else
        {
            QMessageBox::information(nullptr, "Invalid Input", "Please enter name and surname with space inbetween!!");
        }
    }

    return app.exec();
}
