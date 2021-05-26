#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class XML;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void SetTable();
private slots:

    void on_action_Dock_triggered();

    void on_Loadconfig_clicked();

    void on_Newconfig_clicked();

    void on_Loadconfig_clear_clicked();

    void on_Startlog_clear_clicked();

private:
    Ui::MainWindow *ui;
    XML *configxml;

    
protected:
    void dragEnterEvent(QDragEnterEvent *event); // 拖动进入事件
    void dropEvent(QDropEvent *event);           // 放下事件
};

#endif // MAINWINDOW_H
