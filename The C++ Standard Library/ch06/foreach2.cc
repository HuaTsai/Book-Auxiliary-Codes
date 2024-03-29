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
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class PrintInt {
 public:
  void operator()(int elem) const {cout << elem << ' ';}
};

int main() {
  vector<int> coll;

  for (int i = 1; i <= 9; ++i) {
    coll.push_back(i);
  }

  for_each(coll.cbegin(), coll.cend(), PrintInt());
  cout << endl;
}