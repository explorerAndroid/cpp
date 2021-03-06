#include <QFileDialog>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "encryptthread.h"

MainWindow::MainWindow(QWidget* parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::on_chooseSrcFileButton_clicked() {
  QString fileName =
    QFileDialog::getOpenFileName(this, "Выберите исходный файл",
                                 "",
                                 ""); // Все файлы (*.*)");
  ui->srcFileEdit->setText(fileName);
}

void MainWindow::on_chooseDstFileButton_clicked() {
  QString fileName =
    QFileDialog::getSaveFileName(this, "Выберите файл для записи",
                                 "",
                                 ""); // Все файлы (*.*)");
  ui->dstFileEdit->setText(fileName);
}


void MainWindow::on_encodeDecodeButton_clicked() {
  EncryptThread* thread = new EncryptThread(this);
  // Передаём данные потоку
  thread->srcFileName = ui->srcFileEdit->text();
  thread->dstFileName = ui->dstFileEdit->text();

  QProgressBar* progressBar = new QProgressBar(ui->centralWidget);
  progressBar->setValue(0);
  ui->formLayout->addRow(progressBar);

  thread->progressBar = progressBar;

  thread->password = ui->passwordEdit->text();

  // Сигнал из потока
  // направляем в слот главного окна
  connect(thread, SIGNAL(percentsUpdated(int)),
          this, SLOT(updateProgress(int)));

  // Запускаем поток
  thread->start();
}

void MainWindow::updateProgress(int percents) {
  // Получаем отправителя сигнала
  EncryptThread* thread =
    (EncryptThread*)QObject::sender();
  // Обновляем проценты
  thread->progressBar->setValue(percents);
}
