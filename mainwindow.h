#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cmythread.h"
#include "mylabel.h"
#include "selectfourdialog.h"
#include "selecttwodialog.h"
#include <QSettings>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public:
    void InitUI();
    void InitDialog();
    void InitCameras();
    int SixCameraSet();

    void AddUrls();
    //四宫格对话框设置
public slots:
    void FourDialogSet();
    void TwoDialogSet();

    void GetShowInterface(const int nNum);

signals:
    void LabelDoubleClicked(QLabel *pLabel);
private:
    Ui::MainWindow *ui;

    QVector<CMyThread *> QVecThreads;
    QVector<MyLabel *> QVecLabels;
    QVector<MyLabel *> QVecFourLabels;
    QVector<MyLabel *> QVecTwoLabels;
    QVector<QString> QVecLabelNames;

    QVector<QString> QUrls;

    //四宫格界面摄像头tittle
    QVector<QLabel *> QVecFourLabelTittle;

    //六宫格界面摄像头tittle
    QVector<QLabel *> QVecTwoLabelTittle;



    SelectFourDialog *pFourDialog = nullptr;
    SelectTwoDialog *pTwoDialog = nullptr;
};
#endif // MAINWINDOW_H
