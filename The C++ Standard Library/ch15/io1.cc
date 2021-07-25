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
#include <bits/stdc++.h>
using namespace std;

int main() {
  double x, y;
  cout << "Multiplication of two floating point values" << endl;
  cout << "first operand:  ";
  if (!(cin >> x)) {
    cerr << "error while reading the first floating value" << endl;
    return EXIT_FAILURE;
  }
  cout << "second operand: ";
  if (!(cin >> y)) {
    cerr << "error while reading the second floating value" << endl;
    return EXIT_FAILURE;
  }
  cout << x << " times " << y << " equals " << x * y << endl;
}
