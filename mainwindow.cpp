#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent) , ui(new Ui::MainWindow) , zork(new ZorkUL()) , character(new Character("Teran", "He's the detective"))
{
    ui->setupUi(this);

/*    QPixmap p = QPixmap(":/images/images/my_cursor.png");
    QCursor c = QCursor(p, 0, 0);
    setCursor(c); */

    ui->textBox->append(QString::fromStdString(zork->printWelcome()));
    QPixmap pix(QString::fromStdString(":/images/images/Outside.png"));
    ui->displayWin->setPixmap(pix);
    //":/images/images/..." zorkul->getroom()->getname()
}

MainWindow::~MainWindow()
{
    delete ui;
    delete zork;
    delete character;
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

void MainWindow::on_Search_clicked()
{
    if(zork->getRoom()->isClueInRoom()) {
        int max = zork->getRoom()->numberOfClues();
        for(int i=0; i < max; i++ ) {
            character->addClues(zork->getRoom()->getClues()[i]);
            ui->textBox->append(QString::fromStdString(zork->getRoom()->getClues()[i]->getName()));
        }
    }
}
