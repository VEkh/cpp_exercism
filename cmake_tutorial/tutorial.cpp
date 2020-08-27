#include "tutorial_config.h"
#include <iostream>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cout << "Version: " << hottspot_capital_VERSION_MAJOR << "."
              << hottspot_capital_VERSION_MINOR << std::endl;

    std::cout << "Usage: " << argv[0] << " number" << std::endl;

    return 1;
  }

  for (int i = 0; i < argc; i++) {
    std::cout << argv[i] << std::endl;
  }

  return 0;
}
