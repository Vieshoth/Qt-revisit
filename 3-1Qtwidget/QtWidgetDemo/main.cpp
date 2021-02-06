#include <rockwidget.h>
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RockWidget w;
    w.show();
    w.setWindowTitle("Rock widget main");
    return a.exec();
}
