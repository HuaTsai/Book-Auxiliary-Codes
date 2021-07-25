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

void out(bool b) {
  cout << (b ? "found" : "not found") << endl;
}

int main() {
  out(regex_match("<tag>value</tag>", regex("<.*>.*</.*>")));
  out(regex_match("<tag>value</tag>", regex("<(.*)>.*</\\1>")));
  out(regex_match("<tag>value</tag>", regex("<\\(.*\\)>.*</\\1>", regex_constants::grep)));
  cout << endl;
  out(regex_match("XML tag: <tag>value</tag>", regex("<(.*)>.*</\\1>")));
  out(regex_match("XML tag: <tag>value</tag>", regex(".*<(.*)>.*</\\1>.*")));
  out(regex_search("XML tag: <tag>value</tag>", regex("<(.*)>.*</\\1>")));
  out(regex_search("XML tag: <tag>value</tag>", regex(".*<(.*)>.*</\\1>.*")));
}
