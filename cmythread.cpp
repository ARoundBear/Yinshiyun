#include "cmythread.h"

CMyThread::CMyThread(QWidget *parent):QThread(parent)
{

}

CMyThread::~CMyThread()
{
    rep = OpenSDK_StopRealPlay(session);
    if(rep != 0)
    {
        qDebug() << "Close Video Play Error";
    }
    else
    {
        qDebug() << "Close Video Play Success";
    }
    quit();
    wait();
}

void CMyThread::run()
{
    // init library
    rep = OpenSDK_InitLib("https://openauth.ys7.com", "https://open.ys7.com", "4549709deaca429a8505659f8ed9ada8");
    if (rep == 0) {
        std::cout << "init lib success" << std::endl;
    }
    else {
        std::cout << "init lib failed" << std::endl;
        return ;
    }

    // set access token
    rep = OpenSDK_SetAccessToken("at.bx14ll488borlg436rr14x2q9vwoz2v4-4jmg5aw8hs-0j2b8fy-numlew8ot");
    if (rep == 0) {
        std::cout << "set access token success" << std::endl;
    }
    else {
        std::cout << "set access token failed" << std::endl;
        return ;
    }

    // alloc session
    //OpenSDK_MessageHandler msg_handler = MessageHandler;


    rep = OpenSDK_AllocSessionEx(nullptr, user, &session, &length);
    if (rep == 0) {
        std::cout << "alloc session success, session = " << session << std::endl;
    }
    else {
        std::cout << "alloc session failed" << std::endl;
        return ;
    }

//    // set data callback
//    OpenSDK_DataCallBack data_callback = DataCallBack;
//    rep = OpenSDK_SetDataCallBack(session, data_callback, user);
//    if (rep == 0) {
//        std::cout << "set data callback success" << std::endl;
//    }
//    else {
//        std::cout << "set data callback failed" << std::endl;
//        return -1;
//    }

    // set video level
    rep = OpenSDK_SetVideoLevel(m_QStrSerialNumber.toLatin1().data(), m_nChannel, m_nClarityLevel);
    if (rep == 0) {
        std::cout << "set video level success" << std::endl;
    }
    else {
        std::cout << "set video level failed, error code = " << rep << std::endl;
    }
}

int CMyThread::getRep()
{
    return rep;
}

char *CMyThread::GetSession()
{
    if(nullptr != session)
    {
        return session;
    }
    return nullptr;
}

void CMyThread::SetShowsLabel(QLabel *pLabel)
{
   if(nullptr == pLabel)
   {
       qDebug() << "Show in pLabel Is null";
       return ;
   }
   m_pLabel = pLabel;
   // start real play
   hWnd = (HWND)pLabel->winId();
   char *pTmpSession = session;
   int nTmpRep = rep;
   nTmpRep = OpenSDK_StartRealPlayEx(pTmpSession, hWnd, m_QStrSerialNumber.toLatin1().data(), m_nChannel, nullptr);
   if (nTmpRep == 0) {
       std::cout << "start real play success" << std::endl;
   }
   else {
       std::cout << "start real play failed, error code = " << nTmpRep << std::endl;
   }
   return ;
}

QLabel *CMyThread::GetShowedLabel()
{
    if(nullptr == m_pLabel)
    {
        return nullptr;
    }
    return m_pLabel;
}

void CMyThread::SetVideoData(const QString &r)
{
    if(r.isEmpty())
    {
        m_QStrSerialNumber = "NULL";
    }
    else
    {
        m_QStrSerialNumber = r.mid(0 , 9);
        m_nChannel = QString(r[10]).toInt();
        m_nClarityLevel = QString(r[12]).toInt();
    }
}

QString CMyThread::GetSerialNumber()
{
    return m_QStrSerialNumber;
}
