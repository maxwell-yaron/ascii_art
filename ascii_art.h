#include <string>

#include "opencv2/core/core.hpp"

std::string asciiFromImage(const cv::Mat& image, int width, int height, bool invert = false);
