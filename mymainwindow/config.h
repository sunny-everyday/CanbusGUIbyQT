#ifndef CONFIG_H
#define CONFIG_H


#include <QList>

namespace Ui {
class MainWindow;
}


class CONFIG
{
public:
    explicit CONFIG();
    ~CONFIG();


private:
    QList<QMap<QString, QString>>DeviceList;
    void WhiteListtoDeviceList(QList<QStringList> WriteList);
};
#endif // CONFIG_H
