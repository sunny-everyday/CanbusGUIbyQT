#include "xml.h"
#include <QMessageBox>
#include <QList>
#include <QDebug>
#include <QDomDocument>
#include <QUrl>

/*
<?xml version="1.0" encoding="utf-8"?>
<SmartGrid_Config>
  <Host>
    <name>Tensar</name>
    <!--bus type: USBCanI,USBCanII, CANNET,USBCAN_E_U-->
    <connect>USBCANII</connect>
    <description>Host to control devices</description>
  </Host>
  <BusType>
    <Bus ID="0">
      <channelnum>2</channelnum>
      <baudrate>0</baudrate>
    </Bus>
  </BusType>
  <WhiteList>
    <Device ID="0">
      <name>Node0</name>
      <busno>0</busno>
      <channel>0</channel>
      <address>030</address>
      <connect>Disconnected</connect>
      <activity>Tx:0 Rx:0</activity>
      <description>Placed for Demo</description>
      <strainGF>2.08</strainGF>
      <strainR>120</strainR>
      <strainXV>0</strainXV>
      <strainYV>0</strainYV>
      <strainZV>0</strainZV>
    </Device>
  </WhiteList>
</SmartGrid_Config>
*/

void XML::writeXML()
{
    //打开或创建文件
    QString fileName{"config.xml"};
    QFile file(fileName);
    //QIODevice::Truncate表示清空原来的内容
    if(!file.open(QFile::WriteOnly|QFile::Truncate))
        return;

    //创建xml文档在内存中
    QDomDocument doc;
    //添加处理命令
    QDomProcessingInstruction instruction;
    instruction = doc.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"UTF-8\"");
    //创建注释
    QDomComment comment;
    comment = doc.createComment(QString::fromLocal8Bit("SmartGrid Config file"));
    QDomProcessingInstruction styleInstruction;

    doc.appendChild(instruction); //文档开始声明
    doc.appendChild(comment);



    //添加根节点
    QDomElement root=doc.createElement("SmartGrid_Config");
    root.setAttribute("Version","1.0");
    doc.appendChild(root);
    QDomElement host=doc.createElement("Host");
    QDomElement title1=doc.createElement("name"); //创建子元素
    QDomText text1; //设置括号标签中间的值
    text1=doc.createTextNode("Tensar");
    comment = doc.createComment(QString::fromLocal8Bit("bus type: USBCanI,USBCanII, CANNET,USBCAN_E_U"));
    host.appendChild(title1);
    host.appendChild(comment);
    title1.appendChild(text1);

    title1 = doc.createElement("connect"); //创建子元素
    text1=doc.createTextNode("USBCANII");
    host.appendChild(title1);
    title1.appendChild(text1);

    title1 = doc.createElement("description"); //创建子元素
    text1=doc.createTextNode("Host to control devices");
    host.appendChild(title1);
    title1.appendChild(text1);

    root.appendChild(host); //第一个孩子节点添加结束

    QDomElement bus=doc.createElement("BusType");
    QDomElement busID=doc.createElement("Bus");
    busID.setAttribute("ID",0);

    title1 = doc.createElement("channelnum"); //创建子元素
    text1=doc.createTextNode("2");
    busID.appendChild(title1);
    title1.appendChild(text1);

    title1 = doc.createElement("baudrate"); //创建子元素
    text1=doc.createTextNode("0");
    busID.appendChild(title1);
    title1.appendChild(text1);
    bus.appendChild(busID);

    root.appendChild(bus); //第二个孩子节点添加结束

    QDomElement whitelist=doc.createElement("WhiteList");
    QDomElement device=doc.createElement("Device");

    title1 = doc.createElement("name"); //创建子元素
    text1=doc.createTextNode("Node0");
    device.appendChild(title1);
    title1.appendChild(text1);

    title1 = doc.createElement("busno"); //创建子元素
    text1=doc.createTextNode("0");
    device.appendChild(title1);
    title1.appendChild(text1);

    title1 = doc.createElement("channel"); //创建子元素
    text1=doc.createTextNode("0");
    device.appendChild(title1);
    title1.appendChild(text1);

    title1 = doc.createElement("address"); //创建子元素
    text1=doc.createTextNode("1");
    device.appendChild(title1);
    title1.appendChild(text1);


    title1 = doc.createElement("connect"); //创建子元素
    text1=doc.createTextNode("Disconnected");
    device.appendChild(title1);
    title1.appendChild(text1);

    title1 = doc.createElement("activity"); //创建子元素
    text1=doc.createTextNode("Tx:0 Rx:0");
    device.appendChild(title1);
    title1.appendChild(text1);

    title1 = doc.createElement("strainGF"); //创建子元素
    text1=doc.createTextNode("0");
    device.appendChild(title1);
    title1.appendChild(text1);

    title1 = doc.createElement("strainR"); //创建子元素
    text1=doc.createTextNode("0");
    device.appendChild(title1);
    title1.appendChild(text1);
    title1 = doc.createElement("strainXV"); //创建子元素
    text1=doc.createTextNode("0");
    device.appendChild(title1);
    title1.appendChild(text1);
    title1 = doc.createElement("strainYV"); //创建子元素
    text1=doc.createTextNode("0");
    device.appendChild(title1);
    title1.appendChild(text1);
    title1 = doc.createElement("strainZV"); //创建子元素
    text1=doc.createTextNode("0");
    device.appendChild(title1);
    title1.appendChild(text1);

    whitelist.appendChild(device);
    root.appendChild(whitelist); //第三个孩子节点添加结束


    //输出到文件
    QTextStream out_stream(&file);
    doc.save(out_stream,4); //缩进4格
    file.close();
}
/*
<Host>
<name>Tensar</name>
<!--bus type: USBCanI,USBCanII, CANNET,USBCAN_E_U-->
<connect>USBCANII</connect>
<description>Host to control devices</description>
</Host>
<BusType>
<Bus ID="0">
  <channelnum>2</channelnum>
  <baudrate>0</baudrate>
</Bus>
</BusType>
 */
QMap<QString, QString>guiconfighead;
/*
<Device ID="0">
  <name>Node0</name>
  <busno>0</busno>
  <channel>0</channel>
  <address>030</address>
  <connect>Disconnected</connect>
  <activity>Tx:0 Rx:0</activity>
  <description>Placed for Demo</description>
  <strainGF>2.08</strainGF>
  <strainR>120</strainR>
  <strainXV>0</strainXV>
  <strainYV>0</strainYV>
  <strainZV>0</strainZV>
</Device>
*/
QList<QStringList> WhiteList;
bool XML::readXML(QString Filepath)
{
     qDebug()<<"readXML:"<<Filepath;

    //打开或创建文件
    QFile file(Filepath);
    if(!file.open(QFile::ReadOnly))
     {
        qDebug( "open file failed");
        return false;
     }

    QDomDocument doc;
    //设置wangfei1.xml到文档
    if(!doc.setContent(&file))
    {
        file.close();
        return false;
    }
    file.close();

    //返回根节点
    QDomElement root=doc.documentElement();
    qDebug()<<root.nodeName();
    //如果xml根元素有属性（Version）将输出，Vinsion是用户自定义的属性，没有继续执行下一条命令
    if (root.hasAttribute("Version"))  // 属性
        qDebug() << root.attribute("Version");
    /**********根元素之上（XML 声明、注释等）**********/
    QDomNode node = root.previousSibling();
    while (!node.isNull())
    {
        switch (node.nodeType())
        {
        case QDomNode::ProcessingInstructionNode :
        {
            QDomProcessingInstruction instruction = node.toProcessingInstruction();
            //输出处理指令，是用户自定义的，比如字符串“name”对应处理指令得到名字，这个命令是用户写的
            qDebug() << instruction.target() << instruction.data();
            if (QString::compare(instruction.target(), "xml") == 0) // 开始文档（XML 声明）
            {
                //cout<<"处理命令xml"<<endl;
                // ...
            }
            else if (QString::compare(instruction.target(), "xml-stylesheet") == 0) // 处理指令
            {
                //cout<<"处理命令xml-stylesheet"<<endl;
                // ...
            }
            break;
        }
        case QDomNode::CommentNode :
        {
            QDomComment comment = node.toComment();
            qDebug() << comment.data();
            break;
        }
        default:
            break;
        }
        node = node.previousSibling();
    }

    //获得第一个子节点
    node=root.firstChild();
    if(!node.isNull())  //如果节点不空
    {
        if(node.isElement()) //如果节点是元素
        {
            //转换为元素
            QDomElement element=node.toElement();
            if (!element.isNull())// 节点的确是一个元素
            {
                //输出第一个节点
                //qDebug()<<"first node"<<element.tagName();
                if(element.tagName() !=QString::fromLocal8Bit("Host"))
                    return false;

                QDomNodeList list=element.childNodes();
                for(int i=0;i<list.count();++i)
                {
                    QDomNode n=list.at(i);
                    if(n.isElement())
                    {
                        QDomElement Hostinfo=n.toElement();
                        //qDebug()<<Hostinfo.tagName()<<":"<<n.toElement().text();
                        guiconfighead.insert(Hostinfo.tagName(),n.toElement().text());
                    }
                }
            }
        }
        //下一个兄弟节点
        node=node.nextSibling();
        if (!node.isNull())// 节点的确是一个元素
        {
            //转换为元素
            QDomElement element=node.toElement();
            //输出第二个节点
            //qDebug()<<element.tagName()<<" "<<element.attribute("ID");
            if(element.tagName() !=QString::fromLocal8Bit("BusType"))
                return false;

            QDomNodeList list=element.childNodes();
            for(int i=0;i<list.count();++i)
            {
                QDomNode m=list.at(i);
                if(m.isElement())
                {
                    //qDebug()<<m.nodeName()<<":"<<m.toElement().text();
                    QDomNodeList Businfo=m.childNodes();
                    for(int j=0;j<Businfo.count();++j)
                    {
                        QDomNode o=Businfo.at(j);
                        if(o.isElement())
                        {
                            //qDebug()<<o.nodeName()<<":"<<o.toElement().text();
                            guiconfighead.insert(o.nodeName(),o.toElement().text());
                        }
                    }
                }
            }
        }

        //下一个兄弟节点
        //清WhiteList
        foreach(QStringList device,WhiteList)
        {
            WhiteList.removeOne(device);
            qDebug()<<"WhiteList size --"<<WhiteList.size();
        }
        node=node.nextSibling();
        if (!node.isNull())
        {
            //转换为元素
            QDomElement element=node.toElement();
            //输出第三个节点
            //qDebug()<<element.tagName()<<" "<<element.attribute("ID");
            if(element.tagName() !=QString::fromLocal8Bit("WhiteList"))
                return false;

            QDomNodeList list=element.childNodes();
            for(int i=0;i<list.count();++i)
            {
                QStringList SingleDevice;
                QDomNode m=list.at(i);
                if(m.isElement())
                {
                    //qDebug()<<m.nodeName()<<":"<<m.toElement().text();
                    QDomNodeList Businfo=m.childNodes();
                    for(int j=0;j<Businfo.count();++j)
                    {
                        QDomNode o=Businfo.at(j);
                        if(o.isElement())
                        {
                            //qDebug()<<o.nodeName()<<":"<<o.toElement().text();
                            SingleDevice<<o.toElement().text();
                        }
                    }
                }
                WhiteList.append(SingleDevice);
            }

        }
    }
}

void XML::ReadparamList()
{
    QMap<QString,QString>::Iterator it = guiconfighead.begin();

    while(it!=guiconfighead.end())
    {
        qDebug()<<it.key()<<" = " <<it.value();
        it++;
    }

    QList<QStringList>::iterator out = WhiteList.begin();
    while(out!=WhiteList.end())
    {
        QStringList oneRow = *out;
        for(int i = 0;i < 6; ++i )
        {
            QString item = oneRow.at(i);
            qDebug()<<item<<endl;
        }
        out++;
    }

}
//更新桌面列表
void XML::updateTableview(QStandardItemModel* nodelist)
{
    int rowIndex = 0;
    //* 在表格内加入内容 */
    QList<QStringList>::iterator out = WhiteList.begin();
    while(out!=WhiteList.end())
    {
        QStringList oneRow = *out;

        QStandardItem *aItem;
        aItem = new QStandardItem(0,0);
        aItem->setCheckable(true);
        aItem->setCheckState(Qt::Checked);
        //aItem->checkState;
        aItem->setText(oneRow.at(0));
        nodelist->setItem(rowIndex, 0, aItem);
        for(int i = 1;i < 6; ++i )
        {
            QString item = oneRow.at(i);
            nodelist->setItem(rowIndex, i, new QStandardItem(item));
        }

        qDebug()<<(*out);
        out++;
        rowIndex++;
    }



}
//以下代码没有做相应修改 仅供参考
void XML::addXML()
{
    //打开文件
    QFile file("test.xml");
    if(!file.open(QFile::ReadOnly))
        return;
    //增加一个一级子节点以及元素
    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        file.close();
        return;
    }
    file.close();
    //创建根节点
    QDomElement root = doc.documentElement();
    //创建next子节点book
    QDomElement book = doc.createElement("book");
    book.setAttribute("id",3);
    book.setAttribute("time","1813/1/27");
    QDomElement title = doc.createElement("title");
    QDomText text;
    text = doc.createTextNode("Pride and Prejudice");
    //添加text内容到title节点
    title.appendChild(text);
    //添加title到book节点
    book.appendChild(title);
    //添加book到根节点
    root.appendChild(book);

    if(!file.open(QFile::WriteOnly|QFile::Truncate))
        return;
    //输出到文件
    QTextStream out_stream(&file);
    doc.save(out_stream,4); //以缩进4格方式输出，也有其他输出方式（格式）
    file.close();
}
void XML::deleteXML()
{
    //打开文件
    QFile file("test.xml");
    if(!file.open(QFile::ReadOnly))
        return;

    //删除一个一级子节点及其元素，外层节点删除内层节点于此相同
    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        file.close();
        return;
    }
    file.close();

    QDomElement root=doc.documentElement();
    //由标签名定位，本标签为book，以后可以是用string类型的字符串替换，实现动态
    QDomNodeList list=doc.elementsByTagName("book");

    //删除方式一，通过标签book后面的属性删除<book>到</book>
    for(int i=0;i<list.count();i++)
    {
        //转化为元素
        QDomElement e=list.at(i).toElement();
        //找到time是2007/5/25这一条数据将其删除
        if(e.attribute("time")=="2007/5/25")
            root.removeChild(list.at(i));
    }
    //删除方式二，可以通过索引直接删除
//    root.removeChild(list.at(1));

    if(!file.open(QFile::WriteOnly|QFile::Truncate))
        return;
    //输出到文件
    QTextStream out_stream(&file);
    doc.save(out_stream,4); //缩进4格
    file.close();
}

void XML::amendXML()
{
    //打开文件
    QFile file("wangfei1.xml");
    if(!file.open(QFile::ReadOnly))
        return;

    //更新一个标签项,如果知道xml的结构，直接定位到那个标签上定点更新
    //或者用遍历的方法去匹配tagname或者attribut，value来更新
    QDomDocument doc;
    //设置wangfei.xml读到doc文档
    if(!doc.setContent(&file))
    {
        file.close();
        return;
    }
    file.close();

    /**
     *    知道xml结构，直接定位修改
      *   提取根节点
      *
      */
    QDomElement root=doc.documentElement();
    //以book标签存入list
//    QDomNodeList list=root.elementsByTagName("book");
//    QDomNode listNode=list.at(list.size()-2).firstChild();
//    QDomNode oldnode=listNode.firstChild();
//    //把title改成Emma
//    listNode.firstChild().setNodeValue("aaaaaaa");
//    QDomNode newnode=listNode.firstChild();
//    listNode.replaceChild(newnode,oldnode);


    //使用遍历方法选择要修改的元素
//    QDomNodeList lists =doc.childNodes();
//    QDomNodeList list=root.elementsByTagName("book");

    QDomNode node = root.firstChild();

    //QDomNodeList list=root.elementsByTagName("book");

    while(!node.isNull())  //如果节点不空
    {
        if(node.isElement()) //如果节点是元素
        {
            //转换为元素
            QDomElement element=node.toElement();
            if (!element.isNull() && element.attribute("id") == "3")// 节点的确是一个元素
            {
                //输出第一个节点，包括第一个节点的属性，这个属性需要指定属性值，才能输出，如果没有输出空
                //qDebug()<<element.tagName()<<" "<<element.attribute("id")<<" "<<element.attribute("time");
                QDomNodeList list=element.childNodes();
                for(int i=0;i<list.count();++i)
                {
                    QDomNode n=list.at(i);
                    //node = list.at(i);
                    if(node.isElement())
                    {
                        //qDebug()<<n.nodeName()<<":"<<n.toElement().text();
                        element = n.toElement();
                        //与上面qDebug效果相同
                        //qDebug()<<element.nodeName()<<":"<<element.toElement().text();


                        //这个if可以不需要，如果需要精确定位，以防数据相同所以要加这个嵌套if
                        if (QString::compare(element.tagName(), QStringLiteral("title")) == 0)
                        {

                            if("Pride and Prejudice" == element.toElement().text())
                            {
                                // ...处理命令，在这个if里可以遍历想要的节点进行修改
                                //新建一个旧的node缓存
                                QDomNode oldNode = n.firstChild();
                                n.firstChild().setNodeValue("changchun1");
                                //新建一个新的newNode子节点
                                QDomNode newNode = n.firstChild();
                                //使用replaceChild替换node
                                n.replaceChild(newNode,oldNode);
                            }

                        }

                        else if (QString::compare(element.tagName(), QStringLiteral("时间")) == 0)
                        {
                            //cout<<"处理命令时间"<<endl;
                            // ...处理命令
                        }
                        else if (QString::compare(element.tagName(), QStringLiteral("个人说明")) == 0)
                        {
                            //cout<<"处理命令个人说明"<<endl;
                            // ...处理命令
                        }
                    }

                }
            }
        }
        //下一个兄弟节点
        node=node.nextSibling();
    }


    if(!file.open(QFile::WriteOnly|QFile::Truncate))
        return;
    //输出到文件
    QTextStream out_stream(&file);
    doc.save(out_stream,4); //缩进4格
    file.close();

}



