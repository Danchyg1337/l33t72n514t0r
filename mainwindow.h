#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QMessageBox>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionAbout_LeetTrnsltr_triggered();

    void on_button_toLeet_clicked();

    void on_button_toEng_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
