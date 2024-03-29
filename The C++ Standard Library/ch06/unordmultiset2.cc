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
#include <unordered_set>
#include <iostream>

int main() {
  std::unordered_multiset<int> coll;
  coll.insert({1, 3, 5, 7, 11, 13, 17, 19, 23, 27, 1});

  for (auto elem : coll) {
    std::cout << elem << ' ';
  }
  std::cout << std::endl;

  coll.insert(25);
  
  for (auto elem : coll) {
    std::cout << elem << ' ';
  }
  std::cout << std::endl;
}