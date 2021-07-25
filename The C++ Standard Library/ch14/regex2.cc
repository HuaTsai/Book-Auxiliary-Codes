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
  string data = "XML tag: <tag-name>the value</tag-name>.";
  cout << "data:             " << data << "\n\n";
  smatch m;
  bool found = regex_search(data, m, regex("<(.*)>(.*)</(\\1)>"));
  cout << "m.empty():        " << boolalpha << m.empty() << endl;
  cout << "m.size():         " << m.size() << endl;
  if (found) {
    cout << "m.str():          " << m.str() << endl;
    cout << "m.length():       " << m.length() << endl;
    cout << "m.position():     " << m.position() << endl;
    cout << "m.prefix().str(): " << m.prefix().str() << endl;
    cout << "m.suffix().str(): " << m.suffix().str() << endl;
    cout << endl;
    for (size_t i = 0; i < m.size(); ++i) {
      cout << "m[" << i << "].str(): " << m[i].str() << endl;
      cout << "m.str(" << i << "): " << m.str(i) << endl;
      cout << "m.position(" << i << "): " << m.position(i) << endl;
    }
    cout << endl;
    cout << "matches:" << endl;
    for (auto pos = m.begin(); pos != m.end(); ++pos) {
      cout << " " << *pos << " ";
      cout << "(length: " << pos->length() << ")" << endl;
    }
  }
}
