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

void MainWindow::on_action_New_triggered()
{
    // 新建文本编辑器部件
    QTextEdit *edit = new QTextEdit(this);


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
    QFile file(configfilepath);
    if (!file.open(QFile::WriteOnly | QFile::Text))
    {
        //todo 提示文件加载失败
        ui->statusBar->showMessage(tr("文件加载失败"), 4000);
        return ;
    }
    //configxml = new XML();
    configxml->writeXML();
    //生成颗粒列表
    ui->statusBar->showMessage(tr("文件加载成功"), 4000);
}
