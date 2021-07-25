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
  sregex_token_iterator pos(data.cbegin(), data.cend(), reg, {0, 2}), end;
  for (; pos != end; ++pos)
    cout << "match: " << pos->str() << endl;
  cout << endl;
  string names = "nico, jim, helmut, paul, tim, john paul, rita";
  regex sep("[ \t\n]*[,;.][ \t\n]*");
  sregex_token_iterator p(names.cbegin(), names.cend(), sep, -1), e;
  for (; p != e; ++p)
    cout << "name: " << *p << endl;
}
