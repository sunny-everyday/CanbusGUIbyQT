#ifndef XML_H
#define XML_H

#include <QFile>
#include <QTextStream>
#include "qstandarditemmodel.h"
namespace Ui {
class MainWindow;
}


class XML
{

public:
    explicit XML();
    ~XML();

    void writeXML();
    bool readXML(QString Filepath);
    void ReadparamList();
    void updateTableview(QStandardItemModel* nodelist);
    void addXML();
    void deleteXML();
    void amendXML();


};
#endif // XML_H
