#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Imagedialog.h"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <QFileDialog>
#include <QMessageBox>
#include <QInputDialog>

using namespace cv;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionDilatation_Erosion_triggered()
{
    //Change to page 1
    ui->stackedWidget->setCurrentWidget(ui->page_0);
}

void MainWindow::on_actionLighting_triggered()
{
    //Change to page 2
    ui->stackedWidget->setCurrentWidget(ui->page_1);
}

//add picture to certain page
void MainWindow::on_add_picture_triggered()
{

    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("open Image"),
                                                    ".",
                                                    tr("Image Files(*.jpg *.png)"));
    // if don't have image
    if(fileName.isEmpty()){
        return;
    }

    srcImage_page0 = imread(fileName.toLatin1().data());

    cv::cvtColor(srcImage_page0, srcImage_page0, COLOR_BGR2RGB);

    QImage disImage = QImage((const unsigned char*)srcImage_page0.data,
                             srcImage_page0.cols,srcImage_page0.rows,QImage::Format_RGB888);
    originalPixmap= QPixmap::fromImage(disImage);

    if(ui->stackedWidget->currentIndex()==0) {
        originalPixmap_page0=originalPixmap;
        ui->page0_org_img->setPixmap(originalPixmap_page0.scaled(ui->page0_org_img->size(),
                                                           Qt::KeepAspectRatio,
                                                           Qt::SmoothTransformation));
    }else if(ui->stackedWidget->currentIndex()==1) {
        originalPixmap_page1=originalPixmap;
        ui->page1_org_img->setPixmap(originalPixmap_page1.scaled(ui->page1_org_img->size(),
                                                           Qt::KeepAspectRatio,
                                                           Qt::SmoothTransformation));
    }


}



void MainWindow::on_show_org_image_page0_clicked()
{
    if(!originalPixmap_page0.isNull()) {
        ImageDialog *dialog = new ImageDialog(this);
        dialog->setImage(originalPixmap_page0); // Set the image
        dialog->resize(originalPixmap_page0.size()); // Resize dialog to fit the image
        dialog->show(); // Show the dialog
    }else {
        QMessageBox::warning(this, "Error", "No images available to display.");
        return;
    }
}




void MainWindow::on_Dilatation_button_clicked()
{
    if(srcImage_page0.empty()){
        QMessageBox::warning(this, "Error", "No image loaded");
        return;
    }
    // input dialog for Dilation size
    bool ok;
    int dilationSize = QInputDialog::getInt(this, tr("Dilation Size"),
                                            tr("Enter dilation size:(1-20)"), 5, 1, 20, 1, &ok);
    if (!ok) { // if cancel , break
        return;
    }

    cv::Mat element = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(2 * dilationSize + 1, 2 * dilationSize + 1),
                                                cv::Point(dilationSize, dilationSize));
    cv::dilate(srcImage_page0, dilatedImage_page0, element);

    qImg = QImage((const uchar*)dilatedImage_page0.data, dilatedImage_page0.cols, dilatedImage_page0.rows, dilatedImage_page0.step, QImage::Format_RGB888).rgbSwapped();
    QPixmap pixmap = QPixmap::fromImage(qImg);
    ui->page0_cha_img->setPixmap(pixmap.scaled(ui->page0_cha_img->size(),
                                               Qt::KeepAspectRatio,
                                               Qt::SmoothTransformation));

}

void MainWindow::on_Erosion_button_clicked()
{
    if(srcImage_page0.empty()){
        QMessageBox::warning(this, "Error", "No image loaded");
        return;
    }
    // input dialog for Erosion size
    bool ok;
    int erodeSize = QInputDialog::getInt(this, tr("Erosion Size"),
                                            tr("Enter erosion size:(1-20)"), 5, 1, 20, 1, &ok);
    if (!ok) { // if cancel , break
        return;
    }

    cv::Mat element = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(2 * erodeSize + 1, 2 * erodeSize + 1),
                                                cv::Point(erodeSize, erodeSize));
    cv::erode(srcImage_page0, erodeImage_page0, element);

    qImg = QImage((const uchar*)erodeImage_page0.data, erodeImage_page0.cols, erodeImage_page0.rows, erodeImage_page0.step, QImage::Format_RGB888).rgbSwapped();
    QPixmap pixmap = QPixmap::fromImage(qImg);
    ui->page0_cha_img->setPixmap(pixmap.scaled(ui->page0_cha_img->size(),
                                               Qt::KeepAspectRatio,
                                               Qt::SmoothTransformation));
}


void MainWindow::on_show_cha_image_page0_clicked()
{
    if (dilatedImage_page0.empty() && erodeImage_page0.empty()) {
        QMessageBox::warning(this, "Error", "No images available to display.");
        return;
    }

    QMessageBox msgBox;
    msgBox.setWindowTitle("Choose Image");
    msgBox.setText("Which image would you like to display?");
    QPushButton *dilatedButton = msgBox.addButton("Dilated", QMessageBox::AcceptRole);
    QPushButton *erodedButton = msgBox.addButton("Eroded", QMessageBox::RejectRole);

    msgBox.exec();

    cv::Mat imageToShow;
    if (msgBox.clickedButton() == dilatedButton) {
        if (!dilatedImage_page0.empty()) {
            imageToShow = dilatedImage_page0;
        } else {
            QMessageBox::warning(this, "Error", "Dilated image not available.");
            return;
        }
    } else if(msgBox.clickedButton() == erodedButton){
        if (!erodeImage_page0.empty()) {
            imageToShow = erodeImage_page0;
        } else {
            QMessageBox::warning(this, "Error", "Eroded image not available.");
            return;
        }
    }

    qImg = QImage((const uchar*)imageToShow.data, imageToShow.cols, imageToShow.rows, imageToShow.step, QImage::Format_RGB888).rgbSwapped();
    QPixmap pixmap = QPixmap::fromImage(qImg);
    ImageDialog *dialog = new ImageDialog(this);
    dialog->setImage(pixmap); // Set the image
    dialog->resize(pixmap.size()); // Resize dialog to fit the image
    dialog->show(); // Show the dialog
}



void MainWindow::on_download_page0_clicked()
{
    if (qImg.isNull()) {
        QMessageBox::warning(this, "Error", "Failed to convert image.");
        return;
    }

    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Image"), "",
                                                    tr("PNG Files (*.png);;JPEG Files (*.jpg *.jpeg);;BMP Files (*.bmp)"));
    if (!fileName.isEmpty()) {
        qImg.save(fileName);
    }
}
