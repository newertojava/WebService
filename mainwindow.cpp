#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_pQQLabel = new QLabel(this);
    m_pStateLabel = new QLabel(this);
    m_pQQLineEdit = new QLineEdit(this);
    m_pStateLineEdit = new QLineEdit(this);
    m_pSubmitButton = new QPushButton(this);

    m_pStateLineEdit->setReadOnly(true);
    m_pQQLabel->setText(QString::fromLocal8Bit("QQ号码："));
    m_pStateLabel->setText(QString::fromLocal8Bit("QQ状态："));
    m_pSubmitButton->setText(QString::fromLocal8Bit("提交"));

    QGridLayout *pLayout = new QGridLayout();
    pLayout->addWidget(m_pQQLabel, 0, 0);
    pLayout->addWidget(m_pQQLineEdit, 0, 1);
    pLayout->addWidget(m_pStateLabel, 1, 0);
    pLayout->addWidget(m_pStateLineEdit, 1, 1);
    pLayout->addWidget(m_pSubmitButton, 2, 1, 1, 1, Qt::AlignRight);
    pLayout->setSpacing(10);
    pLayout->setContentsMargins(10, 10, 10, 10);
    ui->centralWidget->setLayout(pLayout);

    // 连接信号槽
    m_pHttp = new QtSoapHttpTransport();
    connect(m_pSubmitButton, SIGNAL(clicked()), this, SLOT(onSubmit()));
    connect(m_pHttp, SIGNAL(responseReady(const QtSoapMessage &)), this, SLOT(onResponse(const QtSoapMessage &)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onSubmit(){

    QtSoapMessage message;
    message.setMethod("getAreaDataSet","http://WebXml.com.cn/");
    m_pHttp->setHost("www.webxml.com.cn");
    m_pHttp->setAction("http://WebXml.com.cn/getAreaDataSet");

    m_pHttp->submitRequest(message,"/webservices/ChinaTVprogramWebService.asmx");


    qDebug()<<"send message";
}
void MainWindow::onResponse(const QtSoapMessage& message){
    QString messageStr = message.toXmlString();
    qDebug()<<"str:"<<messageStr;

}
