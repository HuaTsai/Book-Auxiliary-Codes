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
  string data =
      "<person>\n"
      " <first>Nico</first>\n"
      " <last>Josuttis</last>\n"
      "</person>\n";
  regex reg("<(.*)>(.*)</(\\1)>");
  sregex_iterator beg(data.cbegin(), data.cend(), reg), end;
  for_each(beg, end, [](const smatch &m) {
    cout << "match: " << m.str() << endl;
    cout << " tag: " << m.str(1) << endl;
    cout << " value: " << m.str(2) << endl;
  });
}
