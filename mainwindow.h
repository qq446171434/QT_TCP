#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QTcpServer *server;
    QTcpSocket *clientConnection;

public:

    explicit MainWindow(QWidget *parent = nullptr);
    void slot_requestFinished(bool bSuccess, const QString &strResult);
//    void acceptConnection();
//    void readClient();
    ~MainWindow();
private slots:
    void acceptConnection();
    void readClient();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
