#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->label->setText("<b>........</b>");
    ui->textEdit_2->setTextColor(QColor("blue"));
    ui->textEdit_3->setTextColor(QColor("purple"));
    ui->textEdit->append(QString::fromStdString(zork->printWelcome() + "\n"));
    zork = new ZorkUL();
    character = new Character("Teran");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem*item)
{
    string description = item->text().toStdString();
    Item i = *new Item(description);
    ui->listWidget->takeItem(ui->listWidget->row(item));
    //delete item;

    if (putInInventory)
    {
        Room r = zork->getCurrentRoom();
        Item m = r.findClues(i);
        //character.itemsInCharacter.push_back(m);
        addItem(character.itemsInCharacter, m);
        character->addClues(&m);
        ui->textEdit->append(QString::fromStdString(description + " has been added to your inventory.\n"));
    }
}

void MainWindow::showRooms(){
    Room* currentRoom = zork->getRoom();
    string description = currentRoom->shortDescription();
}

void MainWindow::addItemsToListWidget(vector<Item> items)
{
    ui->listWidget->clear();

    if (putInInventory)
    {
        if (!zork->getCurrentRoom().allItemsCollected())
        {
            for (unsigned int i = 0; (unsigned int)i < (unsigned int)zork->getCurrentRoom().numberOfItems(); i++)
            {
                ui->listWidget->addItem(QString::fromStdString(items[i].getShortDescription()));
            }
        }
        else {
            ui->textEdit->append(QString::fromStdString("There are no items in the room."));
        }
    }
    else
    {
        if (!character.itemsInCharacter.empty())
        {
            for (unsigned int i = 0; i < character.itemsInCharacter.size(); i++)
            {
                ui->listWidget->addItem(QString::fromStdString(items[i].getShortDescription()));
            }
        }
        else
        {
            ui->textEdit->append(QString::fromStdString("There are no clues in " + character.shortDescription() + "'s inventory.\n"));
        }
    }
}

void MainWindow::listClues(vector<clues> clues, QString description)
{
    if (!clues.empty())
    {
        addCluesToListWidget(clues);
    }
    else
    {
        ui->textEdit->append("No " + description + " clues could be found.\n");
    }
}

void MainWindow::on_South_clicked()
{
    zork->go("South");
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
