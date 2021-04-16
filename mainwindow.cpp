#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    zork = new ZorkUL();
//  ui->textBox->append(QString::fromStdString(zork->printWelcome() + "\n"));
    character = new Character("Teran");
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
void MainWindow::listClues(vector<clues> clues, QString description)
{
    if (!clues.empty())
    {
        addCluesToListWidget(clues);
    }
    else
    {
        ui->textBox->append("No " + description + " clues could be found.\n");
    }
}
*/
void MainWindow::on_South_clicked()
{
    zork->go("South");
    ui->textBox->append(QString::fromStdString(zork->getRoom()->getDescription()));
}

void MainWindow::on_West_clicked()
{
    zork->go("West");
}

void MainWindow::on_East_clicked()
{
    zork->go("East");
}

void MainWindow::on_North_clicked()
{
    zork->go("North");
}
