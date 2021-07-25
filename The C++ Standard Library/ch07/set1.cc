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
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;

int main() {
  set<int, greater<int>> coll1;
  coll1.insert({4, 3, 5, 1, 6, 2});
  coll1.insert(5);

  for (int elem : coll1) {
    cout << elem << ' ';
  }
  cout << endl;

  auto status = coll1.insert(4);
  if (status.second) {
    cout << "4 inserted as element "
         << distance(coll1.begin(), status.first) + 1 << endl;
  } else {
    cout << "4 already exists" << endl;
  }

  set<int> coll2(coll1.cbegin(), coll1.cend());
  copy(coll2.cbegin(), coll2.cend(), ostream_iterator<int>(cout, " "));
  cout << endl;

  coll2.erase(coll2.begin(), coll2.find(3));

  int num;
  num = coll2.erase(5);
  cout << num << " element(s) removed" << endl;

  copy(coll2.cbegin(), coll2.cend(), ostream_iterator<int>(cout, " "));
  cout << endl;
}