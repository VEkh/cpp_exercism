#include <iostream> // std::cout std::endl
#include <string>   // stod

#include "MathFunctions.h"
#include "tutorial_config.h"

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cout << "Version: " << tutorial_VERSION_MAJOR << "."
              << tutorial_VERSION_MINOR << std::endl;

    std::cout << "Usage: " << argv[0] << " number" << std::endl;

    return 1;
  }

  const double inputValue = std::stod(argv[1]);
  const double outputValue = mathfunctions::sqrt(inputValue);

  std::cout << "The square root of " << inputValue << " is " << outputValue
            << std::endl;
  return 0;
}
