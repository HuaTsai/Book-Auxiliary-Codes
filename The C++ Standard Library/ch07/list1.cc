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
#include <list>
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

void printLists(const list<int> &l1, const list<int> &l2) {
  cout << "list1: ";
  copy(l1.begin(), l1.end(), ostream_iterator<int>(cout, " "));
  cout << endl << "list2: ";
  copy(l2.begin(), l2.end(), ostream_iterator<int>(cout, " "));
  cout << endl << endl;
}

int main() {
  list<int> list1, list2;
  for (int i = 0; i < 6; ++i) {
    list1.push_back(i);
    list2.push_front(i);
  }
  printLists(list1, list2);

  list2.splice(find(list2.begin(), list2.end(), 3), list1);
  printLists(list1, list2);

  list2.splice(list2.end(), list2, list2.begin());
  printLists(list1, list2);

  list2.sort();
  list1 = list2;
  list2.unique();
  printLists(list1, list2);

  list1.merge(list2);
  printLists(list1, list2);
}