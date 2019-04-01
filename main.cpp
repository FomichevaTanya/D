#include <QCoreApplication>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <opencv2/opencv.hpp>
//#include <opencv2/imgproc.hpp>
//#include <opencv2/highgui.hpp>
//#include <opencv2/core.hpp>
//#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
//#include <opencv2/imgcodecs/imgcodecs.hpp>

using namespace std;
using namespace cv;

//int main(int argc, char *argv[])
int main()
{
//QCoreApplication a(argc, argv);

    char keyPress;
    cout<<"hi\n";

    //считываем картинку
    cvNamedWindow("origin",CV_WINDOW_AUTOSIZE);
    Mat image = imread("D:\\origin.jpg", IMREAD_COLOR);

    //показываем картинку
    imshow("origin", image);

    //задаем интересующую область
    Mat roi = image(Rect(15,15,86,86));

    //показываем интересующую область
    imshow("roi", roi);

    //записываем область в файл jpg
    imwrite("roi.jpg", roi);

    while(1)
    {
        keyPress = waitKey();
        //при нажатии клавиши q окно закроется
        if (keyPress == 'q')
        {   //освобождаем ресурсы
            destroyAllWindows();
            break;
        }
    }
    return 0;
//  return a.exec();
}
