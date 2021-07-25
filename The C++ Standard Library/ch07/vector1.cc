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
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

int main() {
  vector<string> sentence;
  sentence.reserve(5);
  sentence.push_back("Hello,");
  sentence.insert(sentence.end(), {"how", "are", "you", "?"});
  copy(sentence.cbegin(), sentence.cend(), ostream_iterator<string>(cout, " "));
  cout << endl;

  cout << " max_size(): " << sentence.max_size() << endl;
  cout << " size(): " << sentence.size() << endl;
  cout << " capacity(): " << sentence.capacity() << endl;

  swap(sentence[1], sentence[3]);
  sentence.insert(find(sentence.begin(), sentence.end(), "?"), "always");

  sentence.back() = "!";

  copy(sentence.cbegin(), sentence.cend(), ostream_iterator<string>(cout, " "));
  cout << endl;

  cout << " size(): " << sentence.size() << endl;
  cout << " capacity(): " << sentence.capacity() << endl;

  sentence.pop_back();
  sentence.pop_back();
  sentence.shrink_to_fit();

  cout << " size(): " << sentence.size() << endl;
  cout << " capacity(): " << sentence.capacity() << endl;
}