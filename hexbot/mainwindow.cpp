#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtNetwork>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(ui->pushButton, &QAbstractButton::clicked, this, &MainWindow::request);
}

void MainWindow::request()
{
    QNetworkRequest request(QUrl("https://api.noopschallenge.com/hexbot"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QNetworkAccessManager manager;
    QNetworkReply* reply = manager.get(request);
    while(!reply->isFinished())
    {
        qApp->processEvents();
    }
    QByteArray response_data = reply->readAll();
    QJsonDocument json = QJsonDocument::fromJson(response_data);
    QJsonObject jsonObject = json.object();
    QJsonArray colorArray = jsonObject.find("colors").value().toArray();
    QString color = colorArray.first().toObject().find("value").value().toString();
    ui->colorLabel->setText(color);
    ui->colorLabel->setStyleSheet("background-color:"+color);
    reply->deleteLater();
}

MainWindow::~MainWindow()
{
    delete ui;
}
