//
// Created by ionut on 5/6/2025.
//

#include "RedEyeProcessor.h"
#include "ImageLoader.h"
#include "RedEyeDetector.h"
#include "RedEyeCorrector.h"
#include <iostream>

#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>

void RedEyeProcessor::run(const std::string& inputPath, const std::string& outputPath) {
    cv::Mat image = ImageLoader::loadImage(inputPath);
    if (image.empty()) {
        std::cerr << "Eroare: imaginea nu a putut fi încărcată de la: " << inputPath << std::endl;
        return;
    }

    double scaleFactor = 1.0;
    int maxWidth = 800;
    int maxHeight = 600;

    if (image.cols > maxWidth || image.rows > maxHeight) {
        double scaleX = static_cast<double>(maxWidth) / image.cols;
        double scaleY = static_cast<double>(maxHeight) / image.rows;
        scaleFactor = std::min(scaleX, scaleY);
    }

    cv::Mat resizedOriginal;
    cv::resize(image, resizedOriginal, cv::Size(), scaleFactor, scaleFactor);
    cv::imshow("Imagine Originala", resizedOriginal);

    RedEyeDetector detector(image);
    auto regions = detector.detect();

    if (regions.empty()) {
        std::cout << "Nu au fost detectate zone de ochii rosii.\n";
    } else {
        std::cout << "S-au detectat " << regions.size() << " regiuni de ochii rosii.\n";
        RedEyeCorrector::correct(image, regions);
    }

    cv::Mat resizedCorrected;
    cv::resize(image, resizedCorrected, cv::Size(), scaleFactor, scaleFactor);
    cv::imshow("Imagine Corectata", resizedCorrected);

    ImageLoader::saveImage(outputPath, image);
    std::cout << "Imaginea a fost salvata la: " << outputPath << std::endl;

    cv::waitKey(0);
}
