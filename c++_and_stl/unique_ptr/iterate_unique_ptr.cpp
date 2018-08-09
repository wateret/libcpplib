//
// Iteration of unique_ptr in containers
//

#include <memory>
#include <vector>
#include <iostream>

using namespace std;

struct DummyStruct {
  int x;
  DummyStruct(int x) : x(x) {}
  void print() { cout << x << endl; }
};

int main() {
  vector<unique_ptr<DummyStruct>> c;

  c.push_back(make_unique<DummyStruct>(1));
  c.push_back(make_unique<DummyStruct>(2));
  c.push_back(make_unique<DummyStruct>(3));

  for (unique_ptr<DummyStruct> const& e : c) e->print();
  for (auto const& e : c) e->print();

  return 0;
}
