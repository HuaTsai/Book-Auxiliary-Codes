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
  cout << regex_replace(data, reg, "<$1 value=\"$2\"/>") << endl;
  cout << regex_replace(data, reg, "<\\1 value=\"\\2\"/>",
                        regex_constants::format_sed)
       << endl;
  string res2;
  regex_replace(
      back_inserter(res2), data.begin(), data.end(), reg, "<$1 value=\"$2\"/>",
      regex_constants::format_no_copy | regex_constants::format_first_only);
  cout << res2 << endl;
}
