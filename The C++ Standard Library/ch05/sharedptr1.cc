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
#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

int main() {
  shared_ptr<string> pNico(new string("nico"));
  shared_ptr<string> pJutta(new string("jutta"));

  (*pNico)[0] = 'N';
  pJutta->replace(0, 1, "J");

  vector<shared_ptr<string>> whoMadeCoffee;
  whoMadeCoffee.push_back(pJutta);
  whoMadeCoffee.push_back(pJutta);
  whoMadeCoffee.push_back(pNico);
  whoMadeCoffee.push_back(pJutta);
  whoMadeCoffee.push_back(pNico);

  for (auto ptr : whoMadeCoffee) {
    cout << *ptr << " ";
  }
  cout << endl;

  *pNico = "Nicolai";
  for (auto ptr : whoMadeCoffee) {
    cout << *ptr << " ";
  }
  cout << endl;

  cout << "use_count: " << whoMadeCoffee[0].use_count() << endl;
}