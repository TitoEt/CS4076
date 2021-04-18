#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    zork = new ZorkUL();
    character = new Character("Teran");

    ui->textBox->append(QString::fromStdString(zork->printWelcome()));
    QPixmap pix(QString::fromStdString(":/images/images/Outside.png"));
    ui->displayWin->setPixmap(pix);
    //":/images/images/..." zorkul->getroom()->getname()
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
    if(zork->go("South")) {
        ui->textBox->append(QString::fromStdString(zork->getRoom()->getName() + zork->getRoom()->getDescription()));
        QPixmap pix(QString::fromStdString(":/images/images/"+zork->getRoom()->getName()+ ".png"));
        ui->displayWin->setPixmap(pix);
    }
}

void MainWindow::on_West_clicked()
{
    if(zork->go("West")) {
        ui->textBox->append(QString::fromStdString(zork->getRoom()->getName() + zork->getRoom()->getDescription()));
        QPixmap pix(QString::fromStdString(":/images/images/"+zork->getRoom()->getName()+ ".png"));
        ui->displayWin->setPixmap(pix);
    }
}

void MainWindow::on_East_clicked()
{
    if(zork->go("East")) {
        ui->textBox->append(QString::fromStdString(zork->getRoom()->getName() + zork->getRoom()->getDescription()));
        QPixmap pix(QString::fromStdString(":/images/images/"+zork->getRoom()->getName()+ ".png"));
        ui->displayWin->setPixmap(pix);
    }
}

void MainWindow::on_North_clicked()
{
    if(zork->go("North")) {
        ui->textBox->append(QString::fromStdString(zork->getRoom()->getName() + zork->getRoom()->getDescription()));
        QPixmap pix(QString::fromStdString(":/images/images/"+zork->getRoom()->getName()+ ".png"));
        ui->displayWin->setPixmap(pix);
    }
}
//this is absolutely not working. but its the closest i got to implementing the inventory
//I absolutelely cried doing this. whelp
void MainWindow::on_Search_clicked(){
    
    if(zork->go("Search")) {
        ui->inventory->append(QString::fromStdString(zork->getRoom()->getName() + zork->getRoom()->getDescription()));
        QPixmap pix(QString::fromStdString(":/images/images/"+zork->getClues()->getShortDescription()+ ".png"));
        ui->displayWin->setPixmap(pix);
    }
    string clue;
    string description = clue->getShortDescription().toStdString();
        string m  = new clues(description);
        ui->inventory->(ui->inventory->row(clues));
        //delete clues;

        if (cluesInRoom <= 0)
        {
            Room* r = zork->getRoom();
            clues* m = r->displayClue();

            addClues(character->cluesInCharacter, m);
            character->addClues(&m);
            r->removeClueFromRoom(m);
            ui->textBox->append(QString::fromStdString(description + " has been added to your inventory.\n"));

        }
}
