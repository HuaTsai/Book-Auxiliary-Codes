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
template <typename ForwardIterator, typename Tp>
inline ForwardIterator find_before(ForwardIterator first, ForwardIterator last,
                                   const Tp &val) {
  if (first == last) {
    return first;
  }
  ForwardIterator next(first);
  ++next;
  while (next != last && !(*next == val)) {
    ++next;
    ++first;
  }
  return first;
}

template <typename ForwardIterator, typename Pred>
inline ForwardIterator find_before_if(ForwardIterator first,
                                      ForwardIterator last, Pred pred) {
  if (first == last) {
    return first;
  }
  ForwardIterator next(first);
  ++next;
  while (next != last && !pred(*next)) {
    ++next;
    ++first;
  }
  return first;
}