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
#include <string>
using namespace std;

int main() {
  multiset<string> cities{"Braunschweig", "Hanover", "Frankfurt", "New Work",
                          "Chicago",      "Toronto", "Paris",     "Frankfurt"};

  for (const auto &elem : cities) {
    cout << elem << " ";
  }
  cout << endl;

  cities.insert({"London", "Munich", "Hanover", "Braunschweig"});

  for (const auto &elem : cities) {
    cout << elem << " ";
  }
  cout << endl;
}