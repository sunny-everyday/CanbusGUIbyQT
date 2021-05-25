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

    QList<QString> DevInformInWhiteList();

};
#endif // CONFIG_H
