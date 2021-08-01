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

using namespace std;
using std::ios;

namespace MyLib {
double readAndProcessSum(std::istream& strm) {
  double value, sum;
  ios::iostate oldExceptions = strm.exceptions();
  /**
   * 1) throw when failbit or badbit is set
   * 2) failbit is also set at end-of-file
   */
  strm.exceptions(ios::failbit | ios::badbit);
  try {
    sum = 0;
    while (strm >> value) {
      sum += value;
    }
  } catch (...) {
    /**
     * If not caused by end-of-file, i.e., !eofbit & (failbit | badbit)
     *   1) restore old state of exception flags
     *   2) rethrow exception
     */
    if (!strm.eof()) {
      strm.exceptions(oldExceptions);
      throw;
    }
  }
  strm.exceptions(oldExceptions);
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
