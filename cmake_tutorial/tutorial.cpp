#include <cmath>    // sqrt
#include <iostream> // std::cout std::endl
#include <string>   // stod

#include "tutorial_config.h"
#ifdef USE_MYMATH
#include "MathFunctions.h"
#endif

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cout << "Version: " << hottspot_capital_VERSION_MAJOR << "."
              << hottspot_capital_VERSION_MINOR << std::endl;

    std::cout << "Usage: " << argv[0] << " number" << std::endl;

    return 1;
  }

  const double inputValue = std::stod(argv[1]);

#ifdef USE_MYMATH
  const double outputValue = mysqrt(inputValue);
#else
  const double outputValue = sqrt(inputValue);
#endif

  std::cout << "The square root of " << inputValue << " is " << outputValue
            << std::endl;
  return 0;
}
