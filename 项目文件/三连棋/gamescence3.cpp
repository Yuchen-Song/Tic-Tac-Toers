#include "gamescence3.h"
#include "ui_gamescence3.h"
#include <QPalette>
#include <QPainter>
#include <QPixmap>
#include <QPen>
#include <QRect>
#include <QBrush>
#include <QMouseEvent>
#include <QDebug>
#include <QLabel>
#include <QListWidget>
#include <QFont>
#include <QTimer>
#include <QMessageBox>
#include <QIcon>
#include <QSize>
#include <vector>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace std;
using namespace cv;


gameScence3::gameScence3(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gameScence3)
{
    ui->setupUi(this);
    //初始化
    this->InitAll();
    this->setFixedSize(QSize(760,760));
    //设立窗口名
    this->setWindowTitle("ChessBorad B!");
    //设立窗口图标
    this->setWindowIcon(QIcon(":/chess.png"));
    //返回按钮
    back=new mypushbutton1;
    back->setParent(this);
    back->setFixedSize(60,30);
    back->setText("back");
    back->move(this->width()-back->width(),this->height()-back->height());
    connect(back,&mypushbutton1::clicked,this,[=](){
        emit leavedB();
    });
   // vector<Vec3d> finalResult(27);
    finalResult.resize(28,10000);

}
void gameScence3:: paintEvent(QPaintEvent *){


    //实例化棋盘的画家
    QPainter painter(this);
    //实例化对战记录的画家
    //抗锯齿
    painter.setRenderHint(QPainter::SmoothPixmapTransform);
    //背景tiaose
    QPalette palette;
    palette.setColor(QPalette::Background,QColor("#B1723C"));
    this->setAutoFillBackground(true);
    this->setPalette(palette);

    //画三连棋的线条
    QPen pen(Qt::black,4);//默认是solidline直线，后期可以改
    painter.setPen(pen);
    //画边界线
    QRect rect(StartX,StartY,this->width()-60,this->height()-60);
    QRect rect2(rect2X,rect2Y,500,500);
    QRect rect3(rect3X,rect3Y,300,300);
    painter.drawRect(rect);
    painter.drawRect(rect2);
    painter.drawRect(rect3);
    //画左对角线
    painter.drawLine(rect3X+300,rect3Y+300, StartX+this->width()-60, StartY+this->height()-60);
    painter.drawLine(StartX,StartY,rect3X,rect3Y);
    //画右对角线
    painter.drawLine(StartX,StartY+700,rect3X,rect3Y+300);
    painter.drawLine(rect3X+300,rect3Y, StartX+this->width()-60, StartY);
    //画横线
    painter.drawLine((this->height())/2,StartX,(this->height())/2,rect3X);
    painter.drawLine((this->width())/2,rect3Y+300,(this->width())/2,this->height()-30);
    //画竖线
    painter.drawLine(StartX,StartY+350,rect3X,rect3Y+150);
    painter.drawLine(rect3X+300,StartY+350,StartX+this->width()-60,rect3Y+150);
    qDebug()<<"hhhh";
    QBrush brush2(Qt::black);
    painter.setBrush(brush2);//设置画刷1形式

    //画棋子
    for (int i=0;i<7;i++) {
         for (int j=0;j<7;j++){
             //若i，j位置为黑棋，i，j位置画棋
             if(color[i][j]==1){
                 QBrush brush2(Qt::black);
                 painter.setBrush(brush2);//设置画刷1形式
                 painter.drawEllipse(chessBoardX[i],chessBoardY[j],60,60);
             }
             //若i，j位置为白  棋，i，j位置画棋
             if(color[i][j]==2){
                 QBrush brush2(Qt::white);
                 painter.setBrush(brush2);//设置画刷1形式
                 painter.drawEllipse(chessBoardX[i],chessBoardY[j],60,60);
             }
         }
    }
}
void gameScence3::paintChess(int row1, int colomn1, int color1){
    //读取结果
    color[row1-1][colomn1-1]=color1;
    update();

}
void gameScence3::InitAll(){

    //换算X坐标
     chessBoardX[0]=StartX-30;
     chessBoardX[1]=rect2X-30;
     chessBoardX[2]=rect3X-30;
     chessBoardX[3]=rect3X+120;
     chessBoardX[4]=rect3X+270;
     chessBoardX[5]=rect2X+470;
     chessBoardX[6]=StartX+this->width()-90;
     //换算Y坐标
     chessBoardY[0]=StartY-30;
     chessBoardY[1]=rect2Y-30;
     chessBoardY[2]=rect3Y-30;
     chessBoardY[3]=rect3Y+120;
     chessBoardY[4]=rect3Y+270;
     chessBoardY[5]=rect2Y+470;
     chessBoardY[6]=StartY+this->height()-90;
     for (int i=0;i<7;i++) {
          for (int j=0;j<7;j++){
              color[i][j]=10000;
          }
     }

     Point center(0, 0);
     Point center1(0, 0);

//     for (int i=1;i<=26;i++) {
//         this->finalResult[i][0]=1000;
//         this->finalResult[i][1]=1000;
//         this->finalResult[i][2]=1000;
//     }
}




//以下是计算机的识别
int gameScence3::detectGrid(cv::Mat img) {
    cv::Mat gray;
        vector<vector<Point> > contours;
        cv::Mat gray_blur;
        cv::Mat thresh;

        cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);


        cv::GaussianBlur(gray, gray_blur, Point(15, 15), 0);


        cv::adaptiveThreshold(gray_blur, thresh, 255, 1, 1, 11, 2);

        cv::Canny(thresh, thresh, canny_1,canny_2, 5, true);
        //cv::imshow("canny", thresh);
        cv::findContours(thresh, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_NONE);
        if (contours.size() != 0) {
            for (int i = 0; i < contours.size(); i++) {
                int max_area = 50000;
                int area = cv::contourArea(contours[i]);
                if (area > max_area) {
                    max_area = area;
                    int best_cnt = i;
                    Rect rect;
                    rect = cv::boundingRect(contours[i]);
                    x = rect.x;
                    y = rect.y;
                    w = rect.width;
                    h = rect.height;
                    cv::rectangle(img, rect, cv::Scalar(0, 255, 0), 2);
                    return x, y, w, h;

                }


            }
        }
        else return 0, 0, 0, 0;
}



//检测结果并且以点的形式输出。第一个分量是位置：键盘九键；第二个是颜色：1黑2白。
void gameScence3::getResult(cv::Mat bgr_image) {

    //定义黑色白色检测上下限
        //根据光线可能需要调整。如果这里能设计一个GUI调整就太好了！可惜我不会！不知道希辰能不能帮上忙

        /*const Scalar hsvWhiteLow(0, 0, 120);
        const Scalar hsvWhiteHigh(255, 255, 255);
        const Scalar hsvBlackLow(0, 0, 0);
        const Scalar hsvBlackHigh(255, 255, 50);
        */

        //进行模糊化和hsv颜色转换

        cv::medianBlur(bgr_image, bgr_image, 3);
        cv::Mat hsv_image;
        cv::cvtColor(bgr_image, hsv_image, cv::COLOR_BGR2HSV);

        //建立白色蒙版
        cv::Mat white_hue_image;
        cv::inRange(hsv_image, Scalar(0, 0, 120), Scalar(255, 255, 255), white_hue_image);
        cv::GaussianBlur(white_hue_image, white_hue_image, cv::Size(15, 15), 1, 1);


        //建立黑色蒙版
        cv::Mat black_hue_image;
        cv::inRange(hsv_image, Scalar(0, 0, 0), Scalar(255, 255, 50), black_hue_image);
        cv::GaussianBlur(black_hue_image, black_hue_image, cv::Size(15, 15), 1, 1);

        //cv::imshow("White", white_hue_image);
        //cv::imshow("Black", black_hue_image);





        cv::cvtColor(bgr_image, gray, cv::COLOR_BGR2GRAY);
        cv::GaussianBlur(gray, gray_blur, Point(15, 15), 0);

        HoughCircles(gray_blur, circles, CV_HOUGH_GRADIENT, 1.5, 50, 100, params2, minR, maxR);
        if (!circles.empty()) {
            for (int i = 0; i < circles.size(); i++) {
                center = Point(cvRound(circles[i][0]), cvRound(circles[i][1]));
                int radius = cvRound(circles[i][2]);
                x, y, w, h = detectGrid(bgr_image);

                if (white_hue_image.at<uchar>(Point(center.x, center.y)) == 255) {
                    cv::circle(bgr_image, center, radius, cv::Scalar(0, 0, 255), 2);
                    whitex = center.x;
                    whitey = center.y;

                    x, y, w, h = detectGrid(bgr_image);
                    row = (int)7*(whitex - x)/w+1;
                    col = (int)7*(whitey - y)/h+1;
                    if (row > 7) row = 7;
                    if (row < 1) row = 1;
                    if (col > 7) col = 7;
                    if (col < 1) col = 1;
                    if ((row == 7 || row == 1 || col == 1 || col == 7) && (col == 2 || col == 3 || col == 5 || col == 6 || row == 2 || row == 3 || row == 5 || row == 6)) {
                        row = 0;
                        col = 0;
                    }
                    if ((row==2||row==6||col==2||col==6)&&(row==3||row==5||col==3||col==5)) {
                        row = 0;
                        col = 0;
                    }
                    detected[i] = 1;
                    finalResult[i][0] = row;
                    finalResult[i][1] = col;
                    finalResult[i][2] = 2;
                    continue;

                }
                else {
                    cv::circle(bgr_image, center, radius, cv::Scalar(255, 0, 0), 2);
                    blackx = center.x;
                    blacky = center.y;
                    x, y, w, h = detectGrid(bgr_image);
                    row = (int)7 * (blackx - x) / w+1;
                    col = (int)7 * (blacky - y) / h+1;
                    if (row > 7) row = 7;
                    if (row < 1) row = 1;
                    if (col > 7) col = 7;
                    if (col < 1) col = 1;
                    if ((row == 7 || row == 1||col==1||col==7) && (col == 2 || col == 3 || col == 5 || col == 6 || row == 2 || row == 3 || row == 5 || row == 6)) {
                        row = 0;
                        col = 0;
                    }
                    if ((row == 2 || row == 6 || col == 2 || col == 6) && (row == 3 || row == 5 || col == 3 || col == 5)) {
                        row = 0;
                        col = 0;
                    }
                    detected[i] = 1;
                    finalResult[i][0] = row;
                    finalResult[i][1] = col;

                    finalResult[i][2] = 1;

                    continue;
                }

            }
        }


        /*for (int i = 0; i < 9; i++) {
            if (detected[i] == 1) {
                cout << i + 1 << r[i] << endl;
                continue;
                return Point(i + 1, r[i]);
            }
            else return Point(0, 0);
        }*/

}

Vec3d gameScence3::show3() {

    for (int i = 0; i < circles.size(); i++) {
        //if (finalResult[i][2]!= 0) {
            cout << finalResult[i] << endl;

            return finalResult[i];
        //}
        //else return 0;
    }
}
void gameScence3::judge3(){

        cv::VideoCapture cap(1);
        cv::Mat frame;

        while (1) {
            cap.read(frame);
            getResult(frame);
            this->show3();
            namedWindow("Parameters Fitting");
            cv::imshow("Parameters Fitting", frame);

            if(char(waitKey(1)) == 'q') {
                return;
            }

            for (int i=0;i<27;i++) {
                this->paintChess(finalResult[i][0],finalResult[i][1],finalResult[i][2]);//这一步代表绘图
            }
            cv::waitKey(1);

        }
}
gameScence3::~gameScence3()
{
    delete ui;
}
