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
#include <algorithm>
#include <iostream>
#include <cstdlib>
using namespace std;

bool isPrime(int number) {
  number = abs(number);
  if (number == 0 || number == 1) { return true; }
  int divisor;
  for (divisor = number / 2; number % divisor != 0; --divisor) {}
  return divisor == 1;
}

int main() {
  list<int> coll;

  for (int i = 24; i <= 30; ++i) {
    coll.push_back(i);
  }

  list<int>::const_iterator pos;
  pos = find_if(coll.cbegin(), coll.cend(), isPrime);

  if (pos != coll.end()) {
    cout << *pos << " is first prime number found" << endl;
  } else {
    cout << "no prime number found" << endl;
  }
}