//
// Created by ionut on 5/6/2025.
//

#include "RedEyeCorrector.h"

void RedEyeCorrector::correct(cv::Mat& image, const std::vector<cv::Rect>& regions) {
    for (const auto& region : regions) {
        cv::Mat roi = image(region);

        for (int y = 0; y < roi.rows; ++y) {
            for (int x = 0; x < roi.cols; ++x) {
                cv::Vec3b& pixel = roi.at<cv::Vec3b>(y, x);
                uchar blue = pixel[0];
                uchar green = pixel[1];
                uchar red = pixel[2];

                if (red > 150 && red > green + 40 && red > blue + 40) {
                    uchar avg = static_cast<uchar>((green + blue) / 2);
                    pixel[2] = avg;
                }
            }
        }
    }
}
