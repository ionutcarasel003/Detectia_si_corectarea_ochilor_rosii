//
// Created by ionut on 5/6/2025.
//

#include "RedEyeProcessor.h"
#include "ImageLoader.h"
#include "RedEyeDetector.h"
#include "RedEyeCorrector.h"

#include <iostream>

void RedEyeProcessor::run(const std::string& inputPath, const std::string& outputPath) {
    cv::Mat image = ImageLoader::loadImage(inputPath);
    if (image.empty()) {
        std::cerr << "Eroare: imaginea nu a putut fi încărcată de la: " << inputPath << std::endl;
        return;
    }

    RedEyeDetector detector(image);
    auto regions = detector.detect();

    if (regions.empty()) {
        std::cout << "Nu au fost detectate zone de ochii rosii.\n";
    } else {
        std::cout << "S-au detectat " << regions.size() << " regiuni de ochii rosii.\n";
        RedEyeCorrector::correct(image, regions);
    }

    ImageLoader::saveImage(outputPath, image);
    std::cout << "Imaginea a fost salvata la: " << outputPath << std::endl;
}