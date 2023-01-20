#include "treewindow.h"
#include "ui_treewindow.h"

treewindow::treewindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::treewindow)
{
    ui->setupUi(this);
    connect(ui->Add, SIGNAL(clicked()),this,SLOT(AddXML()));
}

treewindow::~treewindow()
{
    delete ui;
}
void treewindow::AddXML() {
    QPushButton *button = (QPushButton*)sender();
    std::ifstream file;
    QString name_file = ui->f_name->text();
    file_name = name_file.toStdString();
    file.open(file_name, std::ios::in | std::ios::binary);
    std::ofstream tmp;
    tmp.open("tmp.xml", std::ios::out | std::ios::binary | std::ios::app);
    std::string str;
    while (std::getline(file, str)) {
        if (str != "</sing>") {
            tmp << str;
            tmp << "\n";
        }
    }
    QString name = ui->name->text();
    name_sing = name.toStdString();
    QString text = ui->text->text();
    text_sing = text.toStdString();
    tmp << "\t<sing_name>" << name_sing << "</sing_name>\n";
    tmp << "\t<sing_text>" << text_sing << "</sing_text>\n";
    tmp << "</sing>\n";
    tmp.close();
    file.close();
    std::remove(file_name.c_str());
    std::filesystem::rename("tmp.xml", file_name);
    treewindow::close();
}
