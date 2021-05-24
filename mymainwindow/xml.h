#ifndef XML_H
#define XML_H

#endif // XML_H
#include <QDomDocument>
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

    void XML::writeXML();
    void XML::readXML();
    void XML::addXML();
    void XML::deleteXML();
    void XML::amendXML();
    void writeXMLEG();
};
