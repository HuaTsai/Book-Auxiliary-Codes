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
#include <vector>
#include <deque>
#include <set>
#include <iostream>
using namespace std;

int main() {
  list<int> coll1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  vector<int> coll2;
  copy(coll1.cbegin(), coll1.cend(), back_inserter(coll2));

  deque<int> coll3;
  copy(coll1.cbegin(), coll1.cend(), front_inserter(coll3));

  set<int> coll4;
  copy(coll1.cbegin(), coll1.cend(), inserter(coll4, coll4.begin()));
}