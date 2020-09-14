#ifndef BLOWUPLABEL_H
#define BLOWUPLABEL_H

#include <QObject>
#include <QLabel>
#include "cmythread.h"

class MyLabel;
class BlowUpLabel:public QLabel
{
    Q_OBJECT
public:
    BlowUpLabel(QWidget *parent = nullptr);
    ~BlowUpLabel();

    void mouseDoubleClickEvent(QMouseEvent *event);
public:
    void SetLabel(MyLabel *pLabel);
    void SetThread(CMyThread *pThread);

    void SetPrePalacesInterface(const int nNum);
    int GetPrePalacesInterface();
signals:
    void SendShowInterface(const int nNum);
private:
    MyLabel *m_pLabel = nullptr;
    CMyThread *m_pThread = nullptr;

    int m_PrePalacesInterface = 0;
};

#endif // BLOWUPLABEL_H
