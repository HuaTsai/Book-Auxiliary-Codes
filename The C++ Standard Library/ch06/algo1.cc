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
#include <vector>
using namespace std;

int main() {
  vector<int> coll = {2, 5, 4, 1, 6, 3};
  auto minpos = min_element(coll.cbegin(), coll.cend());
  cout << "min: " << *minpos << endl;
  auto maxpos = max_element(coll.cbegin(), coll.cend());
  cout << "max: " << *maxpos << endl;

  sort(coll.begin(), coll.end());

  auto pos3 = find(coll.begin(), coll.end(), 3);

  reverse(pos3, coll.end());

  for (auto elem : coll) {
    cout << elem << ' ';
  }
  cout << endl;
}