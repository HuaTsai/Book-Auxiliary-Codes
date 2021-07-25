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
#include <chrono>
#include <ctime>
#include <iostream>
#include <string>
using namespace std;

std::string asString(const std::chrono::system_clock::time_point &tp) {
  std::time_t t = std::chrono::system_clock::to_time_t(tp);
  std::string ts = std::ctime(&t);
  ts.resize(ts.size() - 1);
  return ts;
}

int main() {
  typedef chrono::duration<int, ratio<3600 * 24>> Days;

  chrono::time_point<chrono::system_clock> tp;
  cout << "epoch: " << asString(tp) << endl;

  tp += Days(1) + chrono::hours(23) + chrono::minutes(55);
  cout << "later: " << asString(tp) << endl;

  auto diff = tp - chrono::system_clock::time_point();
  cout << "diff: " << chrono::duration_cast<chrono::minutes>(diff).count()
       << " minute(s)" << endl;

  Days days = chrono::duration_cast<Days>(diff);
  cout << "diff: " << days.count() << " day(s)" << endl;

  tp -= chrono::hours(24 * 365);
  cout << "-1 year: " << asString(tp) << endl;

  tp -= chrono::duration<int, ratio<3600 * 24 * 365>>(50);
  cout << "-50 years: " << asString(tp) << endl;

  tp -= chrono::duration<int, ratio<3600 * 24 * 365>>(50);
  cout << "-50 years: " << asString(tp) << endl;
}