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
#include <set>
#include <iostream>
using namespace std;

int main() {
  set<int> coll = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  copy(coll.cbegin(), coll.cend(), ostream_iterator<int>(cout, " "));
  cout << endl;

  int num = coll.erase(3);

  cout << "number of removed elements: " << num << endl;

  copy(coll.cbegin(), coll.cend(), ostream_iterator<int>(cout, " "));
  cout << endl;
}