//
// Created by ionut on 5/6/2025.
//

#include "RedEyeDetector.h"

#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>

RedEyeDetector::RedEyeDetector(const cv::Mat &image) {
    originalImage = image.clone();
    generateMask();
}

void RedEyeDetector::generateMask() {
    cv::Mat imgYCrCb;
    cv::cvtColor(originalImage, imgYCrCb, cv::COLOR_BGR2YCrCb);

    std::vector<cv::Mat> channels;
    cv::split(imgYCrCb, channels);
    cv::threshold(channels[1], mask, 165, 255, cv::THRESH_BINARY);

    cv::medianBlur(mask, mask, 5);
    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(5, 5));
    cv::morphologyEx(mask, mask, cv::MORPH_OPEN, kernel);
    cv::imwrite("D:\\PI\\masca_detectata.jpg", mask);
}

std::vector<cv::Rect> RedEyeDetector::detect () {
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Rect> redEyeRegions;

    cv::findContours(mask, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    for (const auto& contour : contours) {
        cv::Rect box = cv::boundingRect(contour);
        if (box.area() > 100) {
            cv::Rect expandedBox = box;
            int expand = 5;
            expandedBox.x = std::max(0, box.x - expand);
            expandedBox.y = std::max(0, box.y - expand);
            expandedBox.width = std::min(originalImage.cols - expandedBox.x, box.width + 2 * expand);
            expandedBox.height = std::min(originalImage.rows - expandedBox.y, box.height + 2 * expand);

            float aspectRatio = static_cast<float>(expandedBox.width) / expandedBox.height;
            if (aspectRatio > 0.75 && aspectRatio <1.65) {
                redEyeRegions.push_back(expandedBox);
            }
            //redEyeRegions.push_back(expandedBox);
        }
    }

    cv::Mat debugImage = originalImage.clone();
    for (const auto& box : redEyeRegions) {
        cv::rectangle(debugImage, box, cv::Scalar(0, 255, 0), 2);
    }
    cv::imwrite("D:\\PI\\detectie_contururi.jpg", debugImage);

    return redEyeRegions;
}

cv::Mat RedEyeDetector::getMask() const {
    return mask.clone();
}
