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
#include <tuple>
#include <iostream>
#include <complex>
#include <string>
using namespace std;

int main() {
  tuple<string, int, int, complex<double>> t;
  tuple<int, float, string> t1(41, 6.3, "nico");

  cout << get<0>(t1) << " ";
  cout << get<1>(t1) << " ";
  cout << get<2>(t1) << " ";
  cout << endl;

  auto t2 = make_tuple(22, 44, "nico");
  
  get<1>(t1) = get<1>(t2);

  if (t1 < t2) {
    t1 = t2;
  }
}