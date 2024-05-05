#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/opencv.hpp>
#include <opencv2/core/mat.hpp>

#include <QPixmap>

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

    void on_actionDilatation_Erosion_triggered();

    void on_actionLighting_triggered();

    void on_add_picture_triggered();

    void on_show_org_image_page0_clicked();

    void on_Dilatation_button_clicked();

    void on_Erosion_button_clicked();

    void on_show_cha_image_page0_clicked();

    void on_download_page0_clicked();

private:
    Ui::MainWindow *ui;
    // show original picture
    QPixmap originalPixmap;
    QPixmap originalPixmap_page0;
    QPixmap originalPixmap_page1;
    QPixmap originalPixmap_page2;
    QPixmap originalPixmap_page3;
    //page0 image
    cv::Mat srcImage_page0;
    //page0 dilatedImage
    cv::Mat dilatedImage_page0;
    //page0 erodeImage
    cv::Mat erodeImage_page0;
    //the image showed on the label
    QImage qImg;
};

#endif // MAINWINDOW_H
