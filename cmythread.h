#ifndef CMYTHREAD_H
#define CMYTHREAD_H

#include <QWidget>
#include <QThread>
#include <QDebug>
#include <QLabel>

//Yingshiyun_h
#include "INS_ErrorCode.h"
#include "OpenNetStreamDefine.h"
#include "OpenNetStreamError.h"
#include "OpenNetStreamInterFace.h"
#include<iostream>

class CMyThread:public QThread
{
    Q_OBJECT
public:
    CMyThread(QWidget *parent = nullptr);
    ~CMyThread();
public:
    void run();
public:
    int getRep();
    char* GetSession();
    void SetShowsLabel(QLabel *pLabel);
    QLabel *GetShowedLabel();

    void SetVideoData(const QString &r);
    QString GetSerialNumber();
private:
    HWND hWnd;
    int rep;
    char *session = nullptr;
    int length = 0;
    void *user = nullptr;
    QLabel *m_pLabel = nullptr;

    QString m_QStrSerialNumber;
    int m_nChannel;
    int m_nClarityLevel;
};

#endif // CMYTHREAD_H
