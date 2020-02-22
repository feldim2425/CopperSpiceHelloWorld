#pragma once

#include "ui_mainwindow.h"
#include <QMainWindow>

class MainWindow : public QMainWindow {
    CS_OBJECT(MainWindow);

public:
    MainWindow();
    virtual ~MainWindow();

private:
    Ui::MainWindow* m_ui;
};