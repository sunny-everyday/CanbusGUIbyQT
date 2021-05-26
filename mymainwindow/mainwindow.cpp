#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QToolButton>
#include <QSpinBox>
#include <QTextEdit>
#include <QMdiSubWindow>
#include <QLabel>
#include <QDragEnterEvent>
#include <QUrl>
#include <QFile>
#include <QTextStream>
#include <QMimeData>
#include <xml.h>
#include "qstandarditemmodel.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setAcceptDrops(true);

    // 显示临时消息，显示4秒
    ui->statusBar->showMessage(tr("欢迎使用颗粒连接工具"), 4000);
    // 创建标签，设置标签样式并显示信息，然后将其以永久部件的形式添加到状态栏
    QLabel *permanent = new QLabel(this);
    permanent->setFrameStyle(QFrame::Box | QFrame::Sunken);
    permanent->setText("www.Strdal.org");
    ui->statusBar->addPermanentWidget(permanent);
    SetTable();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event) // 拖动进入事件
{
    if(event->mimeData()->hasUrls())                    // 数据中是否包含URL
        event->acceptProposedAction();                  // 如果是则接收动作
    else event->ignore();                               // 否则忽略该事件
}
void MainWindow::dropEvent(QDropEvent *event)           // 放下事件
{
    const QMimeData *mimeData = event->mimeData();      // 获取MIME数据
    if(mimeData->hasUrls()){                            // 如果数据中包含URL
        QList<QUrl> urlList = mimeData->urls();         // 获取URL列表
        // 将其中第一个URL表示为本地文件路径
        QString fileName = urlList.at(0).toLocalFile();
        if(!fileName.isEmpty()){                        // 如果文件路径不为空
            QFile file(fileName);     // 建立QFile对象并且以只读方式打开该文件
            if(!file.open(QIODevice::ReadOnly)) return;
            QTextStream in(&file);                      // 建立文本流对象
            ui->configpath->setText(in.readAll());  // 将文件中所有内容读入编辑器
        }
    }
}


void MainWindow::on_action_Dock_triggered()
{
    ui->dockWidget->show();
}

void MainWindow::on_Loadconfig_clicked()
{
    //当前有can颗粒连接时，不处理配置文件加载
    //读取配置文件名
    QString configfilepath = ui->configpath->toPlainText();

    //读配置文件
    if(configfilepath.isEmpty())
        return;

    //去掉多余斜杠
    if(configfilepath.contains("file:///"))
        configfilepath.replace("file:///","");


    if(!configxml->readXML(configfilepath))
        ui->statusBar->showMessage(tr("文件加载失败"), 4000);
    else
    {
        //打印配置文件的参数信息
        configxml->ReadparamList();
        //生成颗粒列表

        ui->statusBar->showMessage(tr("文件加载成功"), 4000);
    }
    return;
}
void MainWindow::SetTable()
{
    QStandardItemModel* model = new QStandardItemModel();

   /* 设置列数 */
    model->setColumnCount(7);
    model->setHeaderData(0, Qt::Horizontal, "ID");
    model->setHeaderData(1, Qt::Horizontal, "DeviceName");
    model->setHeaderData(2, Qt::Horizontal, "Bus");
    model->setHeaderData(3, Qt::Horizontal, "Channel");
    model->setHeaderData(4, Qt::Horizontal, "Address");
    model->setHeaderData(5, Qt::Horizontal, "Status");
    model->setHeaderData(6, Qt::Horizontal, "Throughput");

   /* 设置行数 */
   model->setRowCount(14);
   model->setHeaderData(0, Qt::Vertical, "1");

   ui->tableView->setModel(model);
   /* 行颜色交替显示 */
   ui->tableView->setAlternatingRowColors(true);
   /* 不允许在图形界面修改内容 */
   ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

   /* 在表格内加入内容 */
   model->setItem(0, 0, new QStandardItem("数学"));

   /* 显示表 */
   ui->tableView->show();
}

void MainWindow::on_Newconfig_clicked()
{
    configxml->writeXML();
    ui->statusBar->showMessage(tr("生成配置文件"), 4000);
}

void MainWindow::on_Loadconfig_clear_clicked()
{
    QString configfilepath = "";
    ui->configpath->setPlainText(configfilepath);
}

void MainWindow::on_Startlog_clear_clicked()
{
    QString configfilepath = "";
    ui->logpath->setPlainText(configfilepath);
}
