#ifndef XML_H
#define XML_H

#include <QFile>
#include <QTextStream>
namespace Ui {
class MainWindow;
}


class XML
{

    public:
    explicit XML();
    ~XML();

    void writeXML();
    void readXML();
    void addXML();
    void deleteXML();
    void amendXML();
    void writeXMLEG();
};
#endif // XML_H
