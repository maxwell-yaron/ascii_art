#include <algorithm>
#include <vector>

#include "opencv2/imgproc/imgproc.hpp"

std::string asciiFromImage(const cv::Mat& image, int width, int height, bool invert = false) {
  if(image.empty() || image.type() != 0) {
    return "";
  }

  std::vector<std::string> lut = {"@", "%", "#", "*", "+", "=", "-", ":", ".", " "};
  if (invert) {
    std::reverse(lut.begin(), lut.end());
  }

  cv::Mat resized;
  cv::resize(image, resized, cv::Size(width, height));

  std::string out_str = "";
  for (int i = 0; i < resized.rows; ++i) {
    uint8_t* rowptr = resized.ptr<uint8_t>(i);
    for (int j = 0; j < resized.cols; ++j) {
      int intensity = (static_cast<double>(rowptr[j]) / 255) * (lut.size() - 1);
      out_str += lut[intensity];
    }
    out_str += "\n";
  }
  return out_str;
}
