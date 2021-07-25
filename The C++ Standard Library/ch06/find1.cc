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
#include <list>
#include <iostream>
using namespace std;

int main() {
  list<int> coll;

  for (int i = 20; i <= 40; ++i) {
    coll.push_back(i);
  }

  auto pos3 = find(coll.begin(), coll.end(), 3);

  reverse(pos3, coll.end());

  list<int>::iterator pos25, pos35;
  pos25 = find(coll.begin(), coll.end(), 25);
  pos35 = find(coll.begin(), coll.end(), 35);

  cout << "max: " << *max_element(pos25, pos35) << endl;
  cout << "max: " << *max_element(pos25, ++pos35) << endl;
}