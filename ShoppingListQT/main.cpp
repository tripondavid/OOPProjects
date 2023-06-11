#include <QApplication>
#include <QPushButton>
#include "Gui.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    std::vector<Item> repoVector;
    auto* repo = new Repository(repoVector);
    Service service = Service(repo);
    Gui gui = Gui(service);

    gui.show();
    return QApplication::exec();
}
