#include "xmlparse.h"
#include "./ui_xmlparse.h"

xmlparse::xmlparse(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::xmlparse)
{
    ui->setupUi(this);
}

xmlparse::~xmlparse()
{
    delete ui;
}

void xmlparse::on_pushButton_clicked()
{
    hide();
    second_window = new SecondWindow(this);
    second_window->show();

}


void xmlparse::on_pushButton_2_clicked()
{
    hide();
    tree_window = new treewindow(this);
    tree_window->show();

}

