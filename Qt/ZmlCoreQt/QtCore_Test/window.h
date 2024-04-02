#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QLibrary>
#include <QMessageBox>
#include <QCloseEvent>
#include <QKeyEvent>
#include <QTimerEvent>

#include "Interface.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Window; }
QT_END_NAMESPACE

class Window : public QMainWindow
{
    Q_OBJECT

public:
    Window(QWidget *parent = nullptr);
    ~Window();

    zml::SystemAPI*             initZmlCore();

protected:
    virtual void                closeEvent(QCloseEvent *event) override;
    virtual void                keyPressEvent(QKeyEvent *event) override;
    virtual void                keyReleaseEvent(QKeyEvent *event) override;
    virtual void                timerEvent(QTimerEvent *event) override;
private:
    Ui::Window *                ui;
    QLibrary*                   m_pLibrary = nullptr;
    zml::SystemAPI*             m_pSystemAPI = nullptr;
    int                         m_nTimerID = 0;
};
#endif // WINDOW_H
