#ifndef XMLPARSE_H
#define XMLPARSE_H

#include <QMainWindow>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <filesystem>
#include <QMessageBox>
#include "secondwindow.h"
#include "treewindow.h"


QT_BEGIN_NAMESPACE
namespace Ui { class xmlparse; }
QT_END_NAMESPACE

class xmlparse : public QMainWindow
{
    Q_OBJECT

public:
    xmlparse(QWidget *parent = nullptr);
    ~xmlparse();

private slots:
       void on_pushButton_clicked();

       void on_pushButton_2_clicked();

private:
    Ui::xmlparse *ui;
    SecondWindow *second_window;
    treewindow *tree_window;
};
#endif // XMLPARSE_H
