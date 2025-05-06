//
// Created by ionut on 5/6/2025.
//

#include "ImageLoader.h"

#include <opencv2/imgcodecs.hpp>

cv::Mat ImageLoader::loadImage(const std::string& path) {
    return cv::imread(path,cv::IMREAD_COLOR);
}

void ImageLoader::saveImage(const std::string& path,const cv::Mat& image) {
    cv::imwrite(path,image);
}
