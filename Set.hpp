#ifndef _SET_HPP_
#define _SET_HPP_

#include "Skiplist.hpp"

template<typename T>
class Set {
public:
    typedef typename Skiplist<T>::iterator iterator;
    Skiplist<T> Set;

    iterator begin() { return Set.begin(); }

    iterator end() { return Set.end(); }

    size_t size() { return Set.size(); }

    void clear() { Set.clear(); }

    bool empty() { return Set.empty(); }

    void insert(const T &elem) {
        if (Set.find(elem) == nullptr)
            Set.insert(elem);
    }

    void erase(const T &elem) { Set.erase(elem); }

    void erase(iterator index) { Set.erase(index); }
};

#endif
