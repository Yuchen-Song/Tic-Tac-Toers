#ifndef GAMESCENCE3_H
#define GAMESCENCE3_H

#include <QMainWindow>
#include <mypushbutton1.h>
#include<iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace std;
using namespace cv;

namespace Ui {
class gameScence3;
}

class gameScence3 : public QMainWindow
{
    Q_OBJECT

public:
    explicit gameScence3(QWidget *parent = nullptr);
    ~gameScence3();
    void  paintEvent(QPaintEvent *);
    void paintChess(int row, int colomn,int color);
    void  InitAll();
    int detectGrid(cv::Mat img);
    void getResult(cv::Mat bgr_image);
    Vec3d show3();
    void judge3();
    //计算机识别
    vector<Vec3f> circles;

    Point center;
    Point center1;
    int radius = 0;
    int radius1 = 0;
    int whitex, whitey, blackx, blacky = 0;
    int r[9] = { 0 };
    int detected[27] = { 0};

    cv::Mat gray_blur;
    cv::Mat gray;

    int params2 = 100;
    int minR = 5;
    int maxR = 40;
    int row = 0;
    int col = 0;
    vector<Vec3d> finalResult;
signals:
    void leavedB();
private:
    Ui::gameScence3 *ui;
    //确立起始坐标点
    int StartX=30;
    int StartY=30;
    int rect2X=130;
    int rect2Y=130;
    int rect3X=230;
    int rect3Y=230;
    int chessBoardX[7];
    int chessBoardY[7];
    int color[7][7];
    mypushbutton1 *back;
    //计算机识别部分
    int x= 0;
    int y = 0;
    int w = 200;
    int h = 200;
    int canny_1 = 100;
    int canny_2 = 150;

};

#endif // GAMESCENCE3_H
