#include <iostream>
#include <opencv2/opencv.hpp>
#include "RedEyeProcessor.h"

int main(int argc, char** argv) {
    if (argc != 3) {
        std::cerr << "Utilizare: " << argv[0] << " <input.jpg> <output.jpg>" << std::endl;
        return 1;
    }

    std::string inputPath = argv[1];
    std::string outputPath = argv[2];

    RedEyeProcessor processor;
    processor.run(inputPath, outputPath);

    return 0;
}