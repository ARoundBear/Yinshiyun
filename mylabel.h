#ifndef MYLABEL_H
#define MYLABEL_H

#include <QWidget>
#include <QLabel>
#include "cmythread.h"
#include "blowuplabel.h"

class MyLabel:public QLabel
{
    Q_OBJECT
public:
    MyLabel(QWidget *parent = nullptr);
    ~MyLabel();
public:
    void mouseDoubleClickEvent(QMouseEvent *event);

signals:
    void doubleClickSignal();
public:
    void SetBlowUpLabel(BlowUpLabel *pBlowUpLabel = nullptr);
    void SetShowThread(CMyThread *pThread);
    CMyThread* GetShowThread();

    void SetLabelName(const QString QStrName);
    QString& GetLabelName();
private:
    CMyThread *m_pThread = nullptr;
    BlowUpLabel *m_pBlowUpLabel = nullptr;
    QString m_QStrName;

};

#endif // MYLABEL_H
