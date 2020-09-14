#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(1920 , 1020);
    setWindowTitle(QString::fromLocal8Bit("监控"));
    void (BlowUpLabel::*pSend)(const int nNum) = &BlowUpLabel::SendShowInterface;
    void (MainWindow::*pReceive)(const int nNum) = &MainWindow::GetShowInterface;

    connect(ui->label , pSend , this , pReceive);
    AddUrls();
    InitDialog();
    InitUI();
    InitCameras();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::InitUI()
{
    ui->stackedWidget->setCurrentIndex(0);
    connect(ui->btn_twoPalaces , &QPushButton::clicked , [=]()
    {
        pTwoDialog->show();
    });
    connect(ui->btn_fourPalaces , &QPushButton::clicked , [=]()
    {
        pFourDialog->show();
    });
    connect(ui->btn_sixPalaces , &QPushButton::clicked , [=]()
    {
        if(ui->stackedWidget->currentIndex() != 0)
        {
            SixCameraSet();
            ui->stackedWidget->setCurrentIndex(0);
        }
    });
}

void MainWindow::InitDialog()
{
    pFourDialog = new SelectFourDialog(this);
    connect(pFourDialog , &SelectFourDialog::ChooseCameras , [=]()
    {
        FourDialogSet();
    });

    pTwoDialog = new SelectTwoDialog(this);
    connect(pTwoDialog , &SelectTwoDialog::ChooseCameras , [=]()
    {
        TwoDialogSet();
    });
}

void MainWindow::InitCameras()
{
    for(int i = 0 ; i < 6 ; i++)
    {
        CMyThread *pThread = new CMyThread();
        pThread->SetVideoData(QUrls[i]);
        QVecThreads.push_back(pThread);
    }

    ui->label_Six1->SetLabelName("马丹1");
    ui->label_Six1->SetLabelName("三沙1");
    ui->label_Six1->SetLabelName("九小1");
    ui->label_Six1->SetLabelName("马丹2");
    ui->label_Six1->SetLabelName("三沙2");
    ui->label_Six1->SetLabelName("九小2");

    QVecLabels.push_back(ui->label_Six1);
    QVecLabels.push_back(ui->label_Six2);
    QVecLabels.push_back(ui->label_Six3);
    QVecLabels.push_back(ui->label_Six4);
    QVecLabels.push_back(ui->label_Six5);
    QVecLabels.push_back(ui->label_Six6);

    QVecFourLabels.push_back(ui->label_Four1);
    QVecFourLabels.push_back(ui->label_Four2);
    QVecFourLabels.push_back(ui->label_Four3);
    QVecFourLabels.push_back(ui->label_Four4);

    QVecTwoLabels.push_back(ui->label_Two1);
    QVecTwoLabels.push_back(ui->label_Two2);

    QVecLabelNames.push_back(QString::fromLocal8Bit("马丹1"));
    QVecLabelNames.push_back(QString::fromLocal8Bit("三沙1"));
    QVecLabelNames.push_back(QString::fromLocal8Bit("九小1"));
    QVecLabelNames.push_back(QString::fromLocal8Bit("马丹2"));
    QVecLabelNames.push_back(QString::fromLocal8Bit("三沙2"));
    QVecLabelNames.push_back(QString::fromLocal8Bit("九小2"));

    for(int i = 0 ; i < 6 ; i++)
    {
        QVecLabels[i]->SetBlowUpLabel(ui->label);
        connect(QVecLabels[i] , &MyLabel::doubleClickSignal , [=]()
        {
            ui->stackedWidget->setCurrentIndex(3);
            ui->label->SetPrePalacesInterface(0);
        });
        if(i < 4)
        {
            QVecFourLabels[i]->SetBlowUpLabel(ui->label);
            connect(QVecFourLabels[i] , &MyLabel::doubleClickSignal , [=]()
            {
                ui->stackedWidget->setCurrentIndex(3);
                ui->label->SetPrePalacesInterface(1);
            });
        }
        if(i < 2)
        {
            QVecTwoLabels[i]->SetBlowUpLabel(ui->label);
            connect(QVecTwoLabels[i] , &MyLabel::doubleClickSignal , [=]()
            {
                ui->stackedWidget->setCurrentIndex(3);
                ui->label->SetPrePalacesInterface(2);
            });
        }
    }

    QVecFourLabelTittle.push_back(ui->label_FourTittle1);
    QVecFourLabelTittle.push_back(ui->label_FourTittle2);
    QVecFourLabelTittle.push_back(ui->label_FourTittle3);
    QVecFourLabelTittle.push_back(ui->label_FourTittle4);

    QVecTwoLabelTittle.push_back(ui->label_TwoTittle1);
    QVecTwoLabelTittle.push_back(ui->label_TwoTittle2);
    for(int i = 0 ; i < QVecThreads.size() ; i++)
    {
        if(QVecThreads[i]->GetSerialNumber() == "NULL")
        {

        }
        else
        {
         QVecThreads[i]->start();
        }
    }

    SixCameraSet();
}

int MainWindow::SixCameraSet()
{
    if(QVecThreads.isEmpty())
    {
        qDebug() << "No Thread";
        return -1;
    }

    for(int i = 0 ; i < QVecThreads.size() ; i++)
    {
        QVecThreads[i]->SetShowsLabel(QVecLabels[i]);
        QVecLabels[i]->SetShowThread(QVecThreads[i]);
    }
    return 0;
}

void MainWindow::AddUrls()
{
    QVector<QString> QVecAddress{"madan1" , "sansha1" , "jiuxiao1" , "madan2" , "sansha2" , "jiuxiao2"};
    QSettings *configIniRead = new QSettings("Urls.ini" , QSettings::IniFormat);
    int nIndex = configIniRead->value("Urls/nCounts").toString().toInt();
    for(int i = 0 ; i < nIndex ; i++)
    {
        QString QStrTmp = QString("SerialNumber-NCHAN-Clarity/");
        QStrTmp += QVecAddress[i];
        QString qStr = configIniRead->value(QStrTmp).toString();
        QUrls.append(qStr);
    }
}

void MainWindow::FourDialogSet()
{
    if(QVecThreads.isEmpty())
    {
        qDebug() << "void MainWindow::FourDialogSet()";
        return;
    }
    int i = 0;
    QVector<int> QTmpVec = pFourDialog->GetQCameras();
    QVector<int>::iterator it = QTmpVec.begin();

    while(it != QTmpVec.end())
    {
        if(i < 4)
        {
          QVecThreads[*it]->SetShowsLabel(QVecFourLabels[i]);
          QVecFourLabels[i]->SetShowThread(QVecThreads[*it]);

          QVecFourLabelTittle[i]->setText(QVecLabelNames[*it]);
          i++;
        }
        it++;
    }
    while(i < 4)
    {
        QVecFourLabelTittle[i]->setText(QString::fromLocal8Bit("无信号"));
        QVecFourLabels[i]->SetShowThread(nullptr);
        i++;
    }
    pFourDialog->ResetCameras();
    pFourDialog->close();
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::TwoDialogSet()
{
    if(QVecThreads.isEmpty())
    {
        qDebug() << "void MainWindow::FourDialogSet()";
        return;
    }
    int i = 0;
    QVector<int> QTmpVec = pTwoDialog->GetQCameras();
    QVector<int>::iterator it = QTmpVec.begin();

    while(it != QTmpVec.end())
    {
        if(i < 2)
        {
          QVecThreads[*it]->SetShowsLabel(QVecTwoLabels[i]);
          QVecTwoLabels[i]->SetShowThread(QVecThreads[*it]);

          QVecTwoLabelTittle[i]->setText(QVecLabelNames[*it]);
          i++;
        }
        it++;
    }
    while(i < 2)
    {
        QVecTwoLabelTittle[i]->setText(QString::fromLocal8Bit("无信号"));
        QVecTwoLabels[i]->SetShowThread(nullptr);
        i++;
    }
    pTwoDialog->ResetCameras();
    pTwoDialog->close();
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::GetShowInterface(const int nNum)
{
    ui->stackedWidget->setCurrentIndex(nNum);
}


