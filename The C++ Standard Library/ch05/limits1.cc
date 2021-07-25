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
#include <limits>
#include <string>
using namespace std;

int main() {
  cout << boolalpha;

  cout << "max(short): " << numeric_limits<short>::max() << endl;
  cout << "max(int): " << numeric_limits<int>::max() << endl;
  cout << "max(long): " << numeric_limits<long>::max() << endl;
  cout << endl;

  cout << "max(float): " << numeric_limits<float>::max() << endl;
  cout << "max(double): " << numeric_limits<double>::max() << endl;
  cout << "max(long double): " << numeric_limits<long double>::max() << endl;
  cout << endl;

  cout << "is_signed(char): " << numeric_limits<char>::is_signed << endl;
  cout << endl;

  cout << "is_specialized(string): " << numeric_limits<string>::is_specialized
       << endl;
}