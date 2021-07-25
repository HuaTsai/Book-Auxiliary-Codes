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
#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>
#include "print.hpp"

int square(int value) { return value * value; }

int main() {
  std::set<int> coll1;
  std::vector<int> coll2;

  for (int i = 1; i <= 9; ++i) {
    coll1.insert(i);
  }
  PRINT_ELEMENTS(coll1, "initialized: ");

  std::transform(coll1.cbegin(), coll1.cend(), std::back_inserter(coll2), square);

  PRINT_ELEMENTS(coll2, "squared: ");
}