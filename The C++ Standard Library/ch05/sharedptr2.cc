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
#include <string>
#include <fstream>
#include <memory>
#include <cstdio>

class FileDeleter {
 public:
  FileDeleter (const std::string& fn) : filename(fn) {}
  void operator() (std::ofstream* fp) {
    fp->close();
    std::remove(filename.c_str());
  }
 private:
  std::string filename;
};

int main() {
  std::shared_ptr<std::ofstream> fp(new std::ofstream("tmpfile.txt"), 
      FileDeleter("tmpfile.txt"));
}