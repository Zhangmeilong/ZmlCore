#include "window.h"
#include "ui_window.h"

Window::Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Window)
{
    ui->setupUi(this);
    m_pLibrary = new QLibrary("./Lanuchd.dll");
}

Window::~Window()
{
    delete ui;

}

void Window::closeEvent(QCloseEvent *event)
{
    killTimer(m_nTimerID);
    if(m_pLibrary->load())
    {
        UninitializeLanuch_ptr pUninitializeLanuch = (UninitializeLanuch_ptr)m_pLibrary->resolve("UninitializeLanuchAPI");
        pUninitializeLanuch();
        delete m_pLibrary;
    }
}

void Window::keyPressEvent(QKeyEvent *event)
{
    int nKey = event->key();
    m_pSystemAPI->iCoreAPI->iKeyEvent(nKey,true);
}

void Window::keyReleaseEvent(QKeyEvent *event)
{
    int nKey = event->key();
    m_pSystemAPI->iCoreAPI->iKeyEvent(nKey,false);
}

void Window::timerEvent(QTimerEvent *event)
{
    m_pSystemAPI->iLanuchAPI->iRunFrame();
}

zml::SystemAPI* Window::initZmlCore()
{
    if(m_pLibrary && m_pLibrary->load())
    {
        InitializeLanuch_ptr pInitializeLanuch = (InitializeLanuch_ptr)m_pLibrary->resolve("InitializeLanuchAPI");
        m_pSystemAPI = pInitializeLanuch("ZmlCore.conf");
        m_nTimerID = startTimer(30,Qt::TimerType::PreciseTimer);
        return m_pSystemAPI;
    }
    return nullptr;
}



