//
// Created by ionut on 5/6/2025.
//

#ifndef REDEYECORRECTOR_H
#define REDEYECORRECTOR_H
#include <opencv2/core/mat.hpp>


class RedEyeCorrector {
public:
    static void correct(cv::Mat& image, const std::vector<cv::Rect>& regions);
};



#endif //REDEYECORRECTOR_H
