#include <QApplication>
#include "MainWindow.h"
#include "Gate.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Gate gate("Main Entrance", "1234");
    MainWindow mainWindow(&gate);
    mainWindow.show();

    return app.exec();
}
