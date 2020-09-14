#include "blowuplabel.h"
#include "mylabel.h"

BlowUpLabel::BlowUpLabel(QWidget *parent):QLabel(parent)
{

}

BlowUpLabel::~BlowUpLabel()
{

}

void BlowUpLabel::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(m_pThread != nullptr && nullptr != m_pLabel)
    {
        m_pThread->SetShowsLabel(m_pLabel);
        emit SendShowInterface(m_PrePalacesInterface);
    }
}

void BlowUpLabel::SetLabel(MyLabel *pLabel)
{
    if(nullptr != pLabel)
    {
        m_pLabel = pLabel;
    }
}

void BlowUpLabel::SetThread(CMyThread *pThread)
{
    if(nullptr != pThread)
    {
        m_pThread = pThread;
    }
}

void BlowUpLabel::SetPrePalacesInterface(const int nNum)
{
    m_PrePalacesInterface = nNum;
}

int BlowUpLabel::GetPrePalacesInterface()
{
    return m_PrePalacesInterface;
}
