//
// A minimal(?) example of range based loop with a custom class
//
// What is needed for the custom class?
//   - A custom class with:
//     - method `IteratorType begin(void)`
//     - method `IteratorType end(void)`
//   - An iterator class for the custom class with:
//     - operator ++ (pre)
//     - operator !=
//     - operator * (indirection)
//
// NOTE The list may not be strictly correct
//
// Related URL
//   - https://stackoverflow.com/a/31457319/2683320

#include <iostream>

class MyClass {
 public:
  class Iterator {
   public:
    Iterator(int* ptr) : ptr_{ptr} {}

    Iterator& operator++ () {
      ptr_++;
      return *this;
    }

    bool operator!= (Iterator& other) const {
      return ptr_ != other.ptr_;
    }

    int& operator* () {
      return *ptr_;
    }

   private:
    int* ptr_;
  };

 public:
  MyClass() = default;

  Iterator begin() { return Iterator{&values_[0]}; }
  Iterator end() { return Iterator{&values_[3]}; }

 private:
  int values_[3] = {1, 2, 3};
};

int main() {
  MyClass myclass;
  for (auto e : myclass) {
    std::cout << e << std::endl;
  }
  std::cout std::endl;

  // Prints "1 2 3"

  return 0;
}
