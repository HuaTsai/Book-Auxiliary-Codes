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
#include <iterator>
#include <list>
#include <iostream>
using namespace std;

int main() {
  list<int> coll;

  for (int i = 1; i <= 6; ++i) {
    coll.push_front(i);
    coll.push_back(i);
  }

  copy(coll.cbegin(), coll.cend(), ostream_iterator<int>(cout, " "));
  cout << endl;

  list<int>::iterator end = remove(coll.begin(), coll.end(), 3);

  copy(coll.begin(), end, ostream_iterator<int>(cout, " "));
  cout << endl;

  cout << "number of removed elements: " << distance(end, coll.end()) << endl;

  coll.erase(end, coll.end());

  copy(coll.cbegin(), coll.cend(), ostream_iterator<int>(cout, " "));
  cout << endl;
}