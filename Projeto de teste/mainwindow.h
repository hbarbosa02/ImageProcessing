#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include "qcustomplot.h"

#include "ImageProcessing/imageprocessing.h"
#include "ImageProcessing/imageconversion.h"
#include "ImageProcessing/imagepreview.h"

#include "SistemasdeControle/headers/graphicLibs/plot.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

private:
    Ui::MainWindow *ui;
    QImage img, img2;
};

#endif // MAINWINDOW_H
