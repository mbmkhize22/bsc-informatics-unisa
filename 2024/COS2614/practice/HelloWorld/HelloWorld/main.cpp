#include <QApplication>
#include <QLabel>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    QLabel *label = new QLabel("Welcome to my app");
    label->setWindowTitle("Maths lesson");
    label->resize(500, 500);
    label->show();

    return app.exec();
}
