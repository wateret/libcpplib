//
// const qualifier position for variables
//
//

#include <iostream>

int main() {
  char s[] = "string";

  std::cout << "char s[] = \"string\"" << std::endl;
  std::cout << "> " << s << std::endl;

  // Define aliases with const qualifier

  const char*  const_0 = s;
  char const * const_1 = s; // Same with `const_0`
  char* const  const_2 = s;

  //////// 1. Modify the contents ////////
  {
#if 0
    const_0[0] = 'S'; // Invalid - error: read-only variable is not assignable
    const_1[0] = 'S'; // Invalid - error: read-only variable is not assignable
#endif

    const_2[0] = 'S'; // Valid

    std::cout << "const_1[0] = 'S'" << s << std::endl;
    std::cout << "> " << s << std::endl;
  }

  //////// 2. Modify the pointer ////////
  {
    char t[] = "another string";

    const_0 = t; // Valid
    std::cout << "const_0 = t" << std::endl;
    std::cout << "> " << const_0 << std::endl;

    const_1 = t; // Valid
    std::cout << "const_1 = t" << std::endl;
    std::cout << "> " << const_1 << std::endl;

#if 0
    const_2 = t; // Invalid - error: cannot assign to variable 'const_2' with const-qualified type 'char *const'
#endif
  }

  return 0;
}
