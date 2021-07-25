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
#include <array>
#include <functional>
#include <numeric>
#include "print.hpp"
using namespace std;

int main() {
  array<int, 10> a = {11, 22, 33, 44};
  PRINT_ELEMENTS(a);

  a.back() = 9999999;
  a[a.size() - 2] = 42;
  PRINT_ELEMENTS(a);

  cout << "sum: " << accumulate(a.begin(), a.end(), 0) << endl;

  transform(a.begin(), a.end(), a.begin(), negate<int>());
  PRINT_ELEMENTS(a);
}