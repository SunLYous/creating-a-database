#include "secondwindow.h"
#include "ui_secondwindow.h"

SecondWindow::SecondWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);
    connect(ui->Add, SIGNAL(clicked()),this,SLOT(CreateXML()));
    connect(ui->Create, SIGNAL(clicked()),this,SLOT(OpenFile()));
    connect(ui->Stop, SIGNAL(clicked()),this,SLOT(StopWrite()));
}

SecondWindow::~SecondWindow()
{
    delete ui;
}
void SecondWindow::OpenFile() {
    QPushButton *button = (QPushButton*)sender();
    std::ofstream file;
    QString name_file = ui->file_name->text();
    file_name = name_file.toStdString();
    file.open(file_name, std::ios::out | std::ios::binary | std::ios::app);
    file << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
    file << "<sing>\n";
    file.close();
}

void SecondWindow::CreateXML() {
    QPushButton *button = (QPushButton*)sender();
    QString name = ui->name->text();
    sing_name = name.toStdString();
    QString text = ui->text->text();
    sing_text = text.toStdString();
    std::ofstream file;
    file.open(file_name, std::ios::out | std::ios::binary | std::ios::app);
    file << "\t<sing_name>" << sing_name << "</sing_name>\n";
    file << "\t<sing_text>" << sing_text << "</sing_text>\n";
}



void SecondWindow::StopWrite() {
    QPushButton *button = (QPushButton*)sender();
    std::ofstream file;
    file.open(file_name, std::ios::out | std::ios::binary | std::ios::app);
    file << "</sing>\n";
    SecondWindow::close();
}



