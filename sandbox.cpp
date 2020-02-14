#include <iostream>

void loop_arrays(int (&arr)[4]);

void loop_arrays(int (&arr)[4]) { std::cout << arr[2] << std::endl; }

int main() {
  int nums[] = {1, 3, 2, 4};

  loop_arrays(nums);
}
