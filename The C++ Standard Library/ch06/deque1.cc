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
#include <deque>
using namespace std;

int main() {
  deque<float> coll;

  for (int i = 1; i <= 6; ++i) {
    coll.push_back(i * 1.1);
  }

  for (size_t i = 0; i < coll.size(); ++i) {
    cout << coll[i] << ' ';
  }
  cout << endl;
}