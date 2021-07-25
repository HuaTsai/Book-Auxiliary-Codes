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
#include <algorithm>
#include <deque>
#include <iostream>
#include <string>
using namespace std;

class Person {
 public:
  Person(string f, string l) : firstname_(f), lastname_(l) {}
  string firstname() const {return firstname_;};
  string lastname() const {return lastname_;};
  friend ostream& operator<<(ostream &out, const Person &p) {
    out << p.firstname_ << ", " << p.lastname_ << " " << endl;
    return out;
  }
 private:
  string firstname_;
  string lastname_;
};

bool personSortCriterion(const Person &p1, const Person &p2) {
  return p1.lastname() < p2.lastname() ||
         (p2.lastname() == p1.lastname() && p1.firstname() < p2.firstname());
}

int main() {
  deque<Person> coll = {Person("a", "a"), Person("a", "b"), Person("b", "a"), Person("b", "b")};
  sort(coll.begin(), coll.end(), personSortCriterion);
  cout << "sorted name" << endl;
  for (auto &elem : coll) {
    cout << elem;
  }
}