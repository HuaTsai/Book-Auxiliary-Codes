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
#include <memory>

class P {
 public:
  P(){}
  ~P() { std::cout << "delete P" << std::endl; }
};

class Q : public std::enable_shared_from_this<Q> {
 public:
  Q(){}
  ~Q() { std::cout << "delete Q" << std::endl; }
  std::shared_ptr<Q> get_shared() { return shared_from_this(); }
};

int main() {
  P* p = new P();
  std::shared_ptr<P> a(p);
  std::shared_ptr<P> b(p);
  std::shared_ptr<P> c(p);
  Q* q = new Q();
  std::shared_ptr<Q> d(q);
  std::shared_ptr<Q> e = q->get_shared();
  std::shared_ptr<Q> f = q->get_shared();
}

