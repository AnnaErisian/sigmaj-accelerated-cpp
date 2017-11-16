#ifndef FUNCTIONS_H
#define FUNCTIONS_H

template <class In>
bool equal(In b, In e, In b2) {
  while(b != e) {
    if(*b != *e) return false;
    ++b;
  }
  return true;
}

template <class In, class X>
In find(In b, In e, X t) {
  while(b != e) {
    if(*b == t) break;
  }
  return b;
}

template <class In, class Out>
In copy(In b, In e, Out d) {
  while(b != e) {
    *d = *b;
    ++d;
    ++b;
  }
  return d;
}

remove_copy_if(b, e, d, p)
transform(b, e, d, f)
accumulate(b, e, t)
search(b, e, b2, e2)
find_if(b, e, p)
remove_copy(b, e, d, t)
remove(b, e, t)
partition(b, e, p)

#endif
