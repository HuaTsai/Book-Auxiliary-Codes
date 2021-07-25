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
  vector<int> coll;
  coll.push_back(2);
  coll.push_back(5);
  coll.push_back(4);
  coll.push_back(1);
  coll.push_back(6);
  coll.push_back(3);

  vector<int>::const_iterator minpos = min_element(coll.cbegin(), coll.cend());
  cout << "min: " << *minpos << endl;
  vector<int>::const_iterator maxpos = max_element(coll.cbegin(), coll.cend());
  cout << "max: " << *maxpos << endl;

  sort(coll.begin(), coll.end());

  vector<int>::iterator pos3;
  pos3 = find(coll.begin(), coll.end(), 3);

  reverse(pos3, coll.end());

  vector<int>::const_iterator pos;
  for (pos = coll.begin(); pos != coll.end(); ++pos) {
    cout << *pos << ' ';
  }
  cout << endl;
}