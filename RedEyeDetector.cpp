//
// Created by ionut on 5/6/2025.
//

#include "RedEyeDetector.h"

#include <opencv2/imgproc.hpp>

RedEyeDetector::RedEyeDetector(const cv::Mat &image) {
    originalImage = image.clone();
    generateMask();
}

void RedEyeDetector::generateMask() {
    cv::Mat imgYCrCb;
    cv::cvtColor(originalImage, imgYCrCb, cv::COLOR_BGR2YCrCb);

    std::vector<cv::Mat> channels;
    cv::split(imgYCrCb, channels);
    cv::threshold(channels[1], mask, 1, 255, cv::THRESH_BINARY);

    cv::medianBlur(mask, mask, 5);
    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(5, 5));
    cv::morphologyEx(mask, mask, cv::MORPH_OPEN, kernel);
}

std::vector<cv::Rect> RedEyeDetector::detect () {
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Rect> redEyeRegions;

    cv::findContours(mask, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    for (const auto& contour : contours) {
        cv::Rect box = cv::boundingRect(contour);
        if (box.area() > 100) {
            redEyeRegions.push_back(box);
        }
    }

    return redEyeRegions;
}

cv::Mat RedEyeDetector::getMask() const {
    return mask.clone();
}
