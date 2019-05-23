#include "ascii_art.h"

#include <iostream>

#include "opencv2/highgui/highgui.hpp"

int main(int argc, char ** argv) {
  const std::string kFilename = std::string(argv[1]);
  int size = 50;
  int h_scale = 2;
  int invert = false;
  if(argc > 4) {
    invert = true;
  }
  if(argc > 3) {
    h_scale = atoi(argv[3]);
  }
  if (argc > 2) {
    size = atoi(argv[2]);
  }

  auto image = cv::imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE);

  std::cout << asciiFromImage(image, size *  h_scale, size, invert) << std::endl;
  return 0;
}
