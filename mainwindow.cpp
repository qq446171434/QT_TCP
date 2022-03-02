#include "mainwindow.h"
#include "httpfun.h"

#include <QDebug>
#include <QHostInfo>
#include <QHostAddress>
#include <QNetworkInterface>
#include <QNetworkAddressEntry>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrlQuery>
#include <QFile>
#include <iostream>
#include <QTcpServer>
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    server = new QTcpServer();
    server->listen(QHostAddress::Any, 12345);
    connect(server, SIGNAL(newConnection()), this, SLOT(acceptConnection()));


}

void MainWindow::acceptConnection()
{
    cout << "acceptConnection" << endl;
    clientConnection = server->nextPendingConnection();
    connect(clientConnection, SIGNAL(readyRead()), this, SLOT(readClient()));
}
void MainWindow::readClient()
{
    QString str = clientConnection->readAll();
    qDebug() << str << endl;
}

void MainWindow::slot_requestFinished(bool bSuccess, const QString &strResult)
{
    if(bSuccess)
    {
//        ui->resultEdit->setPlainText(strResult); //纯文本显示
         cout << strResult.toStdString()<<endl;
    }
    else
    {
//        ui->resultEdit->setPlainText(tr("请求失败！"));
         cout << "请求失败！"<<endl;
    }

}



MainWindow::~MainWindow()
{

}

