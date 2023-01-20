#ifndef TREEWINDOW_H
#define TREEWINDOW_H

#include <QDialog>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <filesystem>
#include <QMessageBox>

namespace Ui {
class treewindow;
}

class treewindow : public QDialog
{
    Q_OBJECT

public:
    explicit treewindow(QWidget *parent = nullptr);
    ~treewindow();

private:
    Ui::treewindow *ui;
    std::string file_name;
    std::string text_sing;
    std::string name_sing;

private slots:
    void AddXML();
};

#endif // TREEWINDOW_H
