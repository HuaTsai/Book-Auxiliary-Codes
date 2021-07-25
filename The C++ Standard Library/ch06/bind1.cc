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
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <set>
#include "print.hpp"
using namespace std;
using namespace std::placeholders;

int main() {
  set<int, greater<int>> coll1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  deque<int> coll2;

  PRINT_ELEMENTS(coll1, "initialized: ");

  transform(coll1.cbegin(), coll1.cend(), back_inserter(coll2),
            bind(multiplies<int>(), _1, 10));

  PRINT_ELEMENTS(coll2, "transformed: ");

  replace_if(coll2.begin(), coll2.end(), bind(equal_to<int>(), _1, 70), 42);

  PRINT_ELEMENTS(coll2, "replaced: ");

  coll2.erase(
      remove_if(coll2.begin(), coll2.end(),
                bind(logical_and<bool>(), bind(greater_equal<int>(), _1, 50),
                     bind(less_equal<int>(), _1, 80))),
      coll2.end());

  PRINT_ELEMENTS(coll2, "removed: ");
}