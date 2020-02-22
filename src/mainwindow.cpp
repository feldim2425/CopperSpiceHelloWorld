#include "mainwindow.hpp"

MainWindow::MainWindow() : QMainWindow(){
    this->m_ui = new Ui::MainWindow();
    this->m_ui->setupUi(this);
}

MainWindow::~MainWindow(){
    delete this->m_ui;
}