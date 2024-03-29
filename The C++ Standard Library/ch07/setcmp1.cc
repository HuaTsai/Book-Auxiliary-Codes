/* The following code example is taken from the book
 * "The C++ Standard Library - A Tutorial and Reference, 2nd Edition"
 * by Nicolai M. Josuttis, Addison-Wesley, 2012
 *
 * (C) Copyright Nicolai M. Josuttis 2012.
 * Permission to copy, use, modify, sell and distribute this software
 * is granted provided this copyright notice appears in all copies.
 * This software is provided "as is" without express or implied
 * warranty, and with no claim as to its suitability for any purpose.
 */
#include <iostream>
#include <set>
#include "print.hpp"
using namespace std;

class RuntimeCmp {
 public:
  enum cmp_mode { normal, reverse };
  RuntimeCmp(cmp_mode m = normal) : mode(m) {}
  template <typename T>
  bool operator()(const T &t1, const T &t2) const {
    return mode == normal ? t1 < t2 : t2 < t1;
  }
  bool operator==(const RuntimeCmp &rc) const {
    return mode == rc.mode;
  }

 private:
  cmp_mode mode;
};

typedef set<int, RuntimeCmp> IntSet;

int main() {
  IntSet coll1 = {4, 7, 5, 1, 6, 2, 5};
  PRINT_ELEMENTS(coll1, "coll1: ");

  RuntimeCmp reverse_order(RuntimeCmp::reverse);

  IntSet coll2(reverse_order);
  coll2 = {4, 7, 5, 1, 6, 2, 5};
  PRINT_ELEMENTS(coll2, "coll2: ");

  coll1 = coll2;
  coll1.insert(3);
  PRINT_ELEMENTS(coll1, "coll1: ");

  if (coll1.value_comp() == coll2.value_comp()) {
    cout << "coll1 and coll2 have same sorting criterion" << endl;
  } else {
    cout << "coll1 and coll2 have different sorting criterion" << endl;
  }
}