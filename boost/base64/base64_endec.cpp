//
// How to use base64 iterators
//

#include <boost/archive/iterators/binary_from_base64.hpp>
#include <boost/archive/iterators/base64_from_binary.hpp>
#include <boost/archive/iterators/transform_width.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/format.hpp>
#include <iostream>
#include <cassert>

namespace Base64 {

std::vector<uint8_t> Decode(const std::string &val) {
  assert(val.size() % 4 == 0);
  using namespace boost::archive::iterators;
  using It = transform_width<binary_from_base64<std::string::const_iterator>, 8, 6>;
  std::vector<uint8_t> tmp(It(std::begin(val)), It(std::end(val)));
  if (val.size() >= 4)
    tmp.resize(tmp.size() - std::count(val.end() - 2, val.end(), '='));
  return tmp;
}

std::string Encode(const std::vector<uint8_t> &val) {
  using namespace boost::archive::iterators;
  using It = base64_from_binary<transform_width<std::vector<uint8_t>::const_iterator, 6, 8>>;
  auto tmp = std::string(It(std::begin(val)), It(std::end(val)));
  return tmp.append((3 - val.size() % 3) % 3, '=');
}

} // namespace Base64

std::ostream& operator<<(std::ostream& os, const std::vector<uint8_t>& vec) {
  os << "[ ";
  for (auto e : vec) {
    os << boost::format("0x%02x") % (int)e << " ";
  }
  os << "]";
  return os;
}

void EndecTest(const std::vector<uint8_t>& bin) {
  std::cout << "======== Base64 Encode/Decode Test ========" << std::endl;
  std::string b64 = Base64::Encode(bin);
  std::cout << "Binary Input  : " << bin << std::endl;
  std::cout << "Base64 Encode : " << b64 << std::endl;
  std::cout << "Base64 Decode : " << Base64::Decode(b64) << std::endl;
  std::cout << std::endl;
}

int main() {
  EndecTest({});
  EndecTest({0x00});
  EndecTest({0x00, 0x00});
  EndecTest({0x00, 0x00, 0x00});
  EndecTest({0x00, 0x00, 0x00, 0x00});
  EndecTest({0xff, 0xff, 0xff, 0xff});

  return 0;
}
