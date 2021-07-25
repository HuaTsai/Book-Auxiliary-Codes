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
#include <cerrno>
#include <cstring>
#include <dirent.h>
#include <iostream>
#include <memory>
#include <string>
using namespace std;

class DirCloser {
public:
  void operator()(DIR *dp) {
    if (closedir(dp) != 0) {
      cerr << "OOPS: closedir() failed" << endl;
    }
  }
};

int main() {
  unique_ptr<DIR, DirCloser> pDir(opendir("."));
  //unique_ptr<DIR, int(*)(DIR *)> pDir(opendir("."), closedir);

  struct dirent *dp;
  while ((dp = readdir(pDir.get())) != nullptr) {
    string filename(dp->d_name);
    cout << "process " << filename << endl;
  }
}
