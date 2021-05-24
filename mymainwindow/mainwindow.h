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

private slots:
    void on_action_New_triggered();

    void on_action_Dock_triggered();

    void on_Loadconfig_clicked();

private:
    Ui::MainWindow *ui;
    XML *configxml;
    
protected:
    void dragEnterEvent(QDragEnterEvent *event); // 拖动进入事件
    void dropEvent(QDropEvent *event);           // 放下事件
};

#endif // MAINWINDOW_H
