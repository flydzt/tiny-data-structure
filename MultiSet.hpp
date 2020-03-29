#ifndef _MULTISET_HPP_
#define _MULTISET_HPP_

#include "Skiplist.hpp"

template<typename T>
class MultiSet {
public:
    typedef typename Skiplist<T>::iterator iterator;
    Skiplist<T> MultiSet;

    iterator begin() { return MultiSet.begin(); }

    iterator end() { return MultiSet.end(); }

    size_t size() { return MultiSet.size(); }

    bool empty() { return MultiSet.empty(); }

    void clear() { return MultiSet.clear(); }

    void insert(const T &elem) { MultiSet.insert(elem); }

    void erase(const T &elem) { MultiSet.erase(elem); }

    void erase(iterator index) { MultiSet.erase(index); }
};

#endif