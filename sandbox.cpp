#include <iostream>
#include <string>
#include <vector>

int main() {
  bool is_greater = "Bool" < "Fool";
  std::vector<int> vector_ = {1, 2, 3};

  std::cout << "Bool is greater than Fool: " << is_greater << std::endl;
  std::cout << "Vector length: " << vector_.size() << std::endl;
}
