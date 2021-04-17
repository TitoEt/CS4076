#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "zorkul.h"
#include "character.h"
#include <QPixmap>


QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_South_clicked();

    void on_West_clicked();

    void on_East_clicked();

    void on_North_clicked();

private:
    Ui::MainWindow *ui;
    void showRooms();
    ZorkUL *zork;
    Character* character;
};
#endif // MAINWINDOW_H
