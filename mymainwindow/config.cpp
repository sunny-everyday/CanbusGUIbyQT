#include "xml.h"
#include <QMessageBox>
#include <QList>
#include "config.h"

QList<QString> CONFIG::DevInformInWhiteList()
{
    QString name;
    QString busno;
    QString channel;
    QString address;
    QString state; //connection status
    QString descript;
    QString activity;
    QString strainXV;
    QString strainYV;
    QString strainZV;
    QString strainR;
    QString strainGF;


    QList<QString> list ;//= new QList<QString>();

    name = "";//TargetNodes.First().Element("name").Value;
    busno = "";//TargetNodes.First().Element("busno").Value;
    channel = "";//TargetNodes.First().Element("channel").Value;
    address = "";//TargetNodes.First().Element("address").Value; //Dev Address in the Serial Bus
    state = "";//;TargetNodes.First().Element("connect").Value;
    activity = "";//TargetNodes.First().Element("activity").Value;
    descript = "";//TargetNodes.First().Element("description").Value;
    strainGF = "";//TargetNodes.First().Element("strainGF").Value;
    strainR = "";//TargetNodes.First().Element("strainR").Value;
    strainXV = "";//TargetNodes.First().Element("strainXV").Value;
    strainYV = "";//TargetNodes.First().Element("strainYV").Value;
    strainZV = "";//TargetNodes.First().Element("strainZV").Value;
/*
    list.Add(name);
    list.Add(busno);
    list.Add(channel);
    list.Add(address);
    list.Add(state);
    list.Add(descript);
    list.Add(strainGF);
    list.Add(strainR);
    list.Add(strainXV);
    list.Add(strainYV);
    list.Add(strainZV);
    */
    return list;

}
