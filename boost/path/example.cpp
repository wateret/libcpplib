//
// How to use base64 iterators
//

#include <boost/filesystem.hpp>
#include <iostream>

int main() {
  boost::filesystem::path p("a/b/c/d");
  std::cout << boost::filesystem::absolute(p) << std::endl;

  return 0;
}
