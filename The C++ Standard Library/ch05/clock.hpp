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
#include <chrono>
#include <iomanip>
#include <iostream>

template <typename C>
void printClockData() {
  using namespace std;
  cout << "- precision: ";
  typedef typename C::period P;
  if (ratio_less_equal<P, milli>::value) {
    typedef typename ratio_multiply<P, kilo>::type TT;
    cout << fixed << double(TT::num) / TT::den << " milliseconds" << endl;
  } else {
    cout << fixed << double(P::num) / P::den << " seconds" << endl;
  }
  cout << "- is_steady: " << boolalpha << C::is_steady << endl;
}