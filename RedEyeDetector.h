//
// Created by ionut on 5/6/2025.
//

#ifndef REDEYEDETECTOR_H
#define REDEYEDETECTOR_H
#include <opencv2/core/mat.hpp>


class RedEyeDetector {
public:
    explicit RedEyeDetector(const cv::Mat& image);
    std::vector<cv::Rect> detect();
    cv::Mat getMask() const;

private:
    cv::Mat originalImage;
    cv::Mat mask;

    void generateMask();
};



#endif //REDEYEDETECTOR_H
