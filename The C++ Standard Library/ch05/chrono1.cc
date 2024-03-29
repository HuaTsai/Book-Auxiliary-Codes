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
#include <string>
#include <iostream>

std::string asString(const std::chrono::system_clock::time_point &tp) {
  std::time_t t = std::chrono::system_clock::to_time_t(tp);
  std::string ts = std::ctime(&t);
  ts.resize(ts.size() - 1);
  return ts;
}

int main() {
  std::chrono::system_clock::time_point tp;
  std::cout << "epoch: " << asString(tp) << std::endl;

  tp = std::chrono::system_clock::now();
  std::cout << "now: " << asString(tp) << std::endl;

  tp = std::chrono::system_clock::time_point::min();
  std::cout << "min: " << asString(tp) << std::endl;

  tp = std::chrono::system_clock::time_point::max();
  std::cout << "max: " << asString(tp) << std::endl;
}