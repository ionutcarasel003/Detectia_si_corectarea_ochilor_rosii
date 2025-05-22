#include <iostream>
#include <opencv2/opencv.hpp>
#include "RedEyeProcessor.h"

int main(int argc, char** argv) {

    RedEyeProcessor processor;
    processor.run("D:\\PI\\Poza_de_test1.jpg", "D:\\PI\\Poza_rezultat1.jpg");
    processor.run("D:\\PI\\Poza_de_test2.jpg", "D:\\PI\\Poza_rezultat2.jpg");
    processor.run("D:\\PI\\Poza_de_test3.jpg", "D:\\PI\\Poza_rezultat3.jpg");
    return 0;
}