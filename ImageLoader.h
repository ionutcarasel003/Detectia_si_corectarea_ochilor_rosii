//
// Created by ionut on 5/6/2025.
//

#ifndef IMAGELOADER_H
#define IMAGELOADER_H
#include <string>
#include <opencv2/core/mat.hpp>


class ImageLoader {
    public:
        static cv::Mat loadImage(const std::string& path);
        static void saveImage(const std::string& path, const cv::Mat& image);
    private:
        ImageLoader() = delete;
};



#endif //IMAGELOADER_H
