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
#include <bits/stdc++.h>
#include <ios>
using namespace std;

namespace MyLib {
double readAndProcessSum(std::istream& strm) {
  double value, sum;
  sum = 0;
  while (strm >> value)
    sum += value;
  if (!strm.eof())
    throw std::ios::failure("input error in readAndProcessSum()");
  return sum;
}
}

int main() {
  double sum;
  try {
    sum = MyLib::readAndProcessSum(cin);
  } catch (const ios::failure& error) {
    cerr << "I/O exception: " << error.what() << endl;
    return EXIT_FAILURE;
  } catch (const exception& error) {
    cerr << "standard exception: " << error.what() << endl;
    return EXIT_FAILURE;
  } catch (...) {
    cerr << "unknown exception" << endl;
    return EXIT_FAILURE;
  }
  cout << "sum: " << sum << endl;
}
