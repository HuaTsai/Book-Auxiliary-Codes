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
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

int main() {
  deque<string> coll;

  coll.assign(3, string("string"));
  coll.push_back("last string");
  coll.push_front("first string");

  copy(coll.cbegin(), coll.cend(), ostream_iterator<string>(cout, "\n"));
  cout << endl;

  coll.pop_front();
  coll.pop_back();

  for (unsigned i = 1; i < coll.size(); ++i) {
    coll[i] = "another " + coll[i];
  }

  coll.resize(4, "resized string");

  copy(coll.cbegin(), coll.cend(), ostream_iterator<string>(cout, "\n"));
}