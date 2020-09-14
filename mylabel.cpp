#include "mylabel.h"

MyLabel::MyLabel(QWidget *parent):QLabel(parent)
{

}

MyLabel::~MyLabel()
{

}

void MyLabel::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(nullptr == m_pThread)
    {

    }
    else
    {
        m_pBlowUpLabel->SetThread(m_pThread);
        m_pBlowUpLabel->SetLabel(this);
        m_pThread->SetShowsLabel(m_pBlowUpLabel);
        emit doubleClickSignal();
    }
}

void MyLabel::SetBlowUpLabel(BlowUpLabel *pBlowUpLabel)
{
    m_pBlowUpLabel = pBlowUpLabel;
}

void MyLabel::SetShowThread(CMyThread *pThread)
{
    if(nullptr == pThread)
    {
        m_pThread = nullptr;
        return;
    }
    m_pThread = pThread;
}

CMyThread *MyLabel::GetShowThread()
{
    if(m_pThread == nullptr)
    {
        qDebug() << "Label has Set Thread is null";
        return nullptr;
    }
    return m_pThread;
}

void MyLabel::SetLabelName(const QString QStrName)
{
    m_QStrName = QStrName;
}

QString &MyLabel::GetLabelName()
{
    return m_QStrName;
}
