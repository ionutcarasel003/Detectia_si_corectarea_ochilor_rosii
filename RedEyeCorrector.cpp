#include "RedEyeCorrector.h"
#include <opencv2/imgproc.hpp>

void RedEyeCorrector::correct(cv::Mat& image, const std::vector<cv::Rect>& regions) {
    for (const auto& region : regions) {
        cv::Mat roi = image(region);

        for (int y = 0; y < roi.rows; ++y) {
            for (int x = 0; x < roi.cols; ++x) {
                cv::Vec3b& pixel = roi.at<cv::Vec3b>(y, x);
                uchar blue = pixel[0];
                uchar green = pixel[1];
                uchar red = pixel[2];

                if (red > 80 && red > green + 30 && red > blue + 30) {
                    uchar newRed = static_cast<uchar>((green + blue) / 2);
                    pixel[2] = newRed;
                }

            }
        }
    }
}
