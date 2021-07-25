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
#include <list>
#include <algorithm>
#include <iostream>
#include "print.hpp"
using namespace std;

class AddValue {
 public:
  AddValue(int v) : theValue(v){}
  void operator()(int &elem) const {elem += theValue;}
 private:
  int theValue;
};

int main() {
  list<int> coll;

  for (int i = 1; i <= 9; ++i) {
    coll.push_back(i);
  }

  PRINT_ELEMENTS(coll, "initialized: ");

  for_each(coll.begin(), coll.end(), AddValue(10));

  PRINT_ELEMENTS(coll, "after add 10: ");

  for_each(coll.begin(), coll.end(), AddValue(*coll.begin()));

  PRINT_ELEMENTS(coll, "after add first elem: ");
}