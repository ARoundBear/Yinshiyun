#include "selecttwodialog.h"
#include "ui_selecttwodialog.h"

SelectTwoDialog::SelectTwoDialog(QWidget *parent) :
    QDialog(parent , Qt::FramelessWindowHint),
    ui(new Ui::SelectTwoDialog)
{
    ui->setupUi(this);
    this->setWindowTitle(QString::fromLocal8Bit("两宫格选择"));
    this->setFixedSize(400 , 300);
    ui->label_2->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    connect(ui->btn_confirm , &QPushButton::clicked , this , [=]()
    {
        if(ui->checkBox_camera1->isChecked())
        {
            QCameras.push_back(0);
        }
        if(ui->checkBox_camera2->isChecked())
        {
            QCameras.push_back(1);
        }
        if(ui->checkBox_camera3->isChecked())
        {
            QCameras.push_back(2);
        }
        if(ui->checkBox_camera4->isChecked())
        {
            QCameras.push_back(3);
        }
        if(ui->checkBox_camera5->isChecked())
        {
            QCameras.push_back(4);
        }
        if(ui->checkBox_camera6->isChecked())
        {
            QCameras.push_back(5);
        }
        ui->checkBox_camera1->setCheckState(Qt::Unchecked);
        ui->checkBox_camera2->setCheckState(Qt::Unchecked);
        ui->checkBox_camera3->setCheckState(Qt::Unchecked);
        ui->checkBox_camera4->setCheckState(Qt::Unchecked);
        ui->checkBox_camera5->setCheckState(Qt::Unchecked);
        ui->checkBox_camera6->setCheckState(Qt::Unchecked);

        if(QCameras.size() != 0)
        {
            emit this->ChooseCameras();
        };
    });

    connect(ui->btn_Cancel , &QPushButton::clicked , [=]()
    {
        ui->checkBox_camera1->setCheckState(Qt::Unchecked);
        ui->checkBox_camera2->setCheckState(Qt::Unchecked);
        ui->checkBox_camera3->setCheckState(Qt::Unchecked);
        ui->checkBox_camera4->setCheckState(Qt::Unchecked);
        ui->checkBox_camera5->setCheckState(Qt::Unchecked);
        ui->checkBox_camera6->setCheckState(Qt::Unchecked);
        close();
    });
}

QVector<int> SelectTwoDialog::GetQCameras()
{
    if(!QCameras.isEmpty())
    {
        return QCameras;
    }
}

void SelectTwoDialog::SetQCameras(QVector<int> QTemps)
{
    if(!QTemps.isEmpty())
    {
        QCameras = QTemps;
    }
}

bool SelectTwoDialog::ResetCameras()
{
   if(QCameras.isEmpty())
   {
       return false;
   }
   QCameras.clear();
   return true;
}


SelectTwoDialog::~SelectTwoDialog()
{
    QCameras.clear();
    QCameras.shrink_to_fit();
    delete ui;
}
