#include <iostream>

enum class Direction {
  kLeft   = 0x01,
  kRight  = 0x02,
  kTop    = 0x04,
  kBottom = 0x08,
  kLeftTop = kLeft | kTop // Valid
};

int main() {
  Direction dir1 = Direction::kLeftTop;
  std::cout << (unsigned int)dir1 << std::endl; // Prints "5"

#if 0
  Direction dir2 = Direction::kLeft | Direction::kRight;    // Invalid - Cannot use OR operator
#endif

  return 0;
}
