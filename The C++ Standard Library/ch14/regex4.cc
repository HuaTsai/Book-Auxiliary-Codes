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

int main() {
  string pat1 = R"(\\.*index\{([^}]*)\})";
  string pat2 = R"(\\.*index\{(.*)\}\{(.*)\})";
  regex pat(pat1 + "\n" + pat2, regex_constants::egrep | regex_constants::icase);
  string data((istreambuf_iterator<char>(cin)), istreambuf_iterator<char>());
  smatch m;
  auto pos = data.cbegin();
  auto end = data.cend();
  for (; regex_search(pos, end, m, pat); pos = m.suffix().first) {
    cout << "match: " << m.str() << endl;
    cout << "  val: " << m.str(1) + m.str(2) << endl;
    cout << "  see: " << m.str(3) << endl;
  }
}
