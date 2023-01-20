#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <filesystem>
#include <QMessageBox>


namespace Ui {
class SecondWindow;
}

class SecondWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow();


private slots:
    void CreateXML();
    void StopWrite();
    void OpenFile();

private:
    Ui::SecondWindow *ui;
        std::string sing_name;
        std::string sing_text;
        std::string file_name;
};

#endif // SECONDWINDOW_H
