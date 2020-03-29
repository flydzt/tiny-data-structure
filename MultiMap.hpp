#ifndef _MULTIMAP_HPP_
#define _MULTIMAP_HPP_

#include "Skiplist.hpp"
#include "Pair.hpp"

template<typename T, typename S>
class MultiMap {
public:
    typedef typename Skiplist<Pair<T, S>>::iterator iterator;
    typedef T first_type;
    typedef S second_type;
    typedef Pair<T, S> value_type;
    Skiplist<Pair<T, S>> MultiMap;

    iterator begin() { return MultiMap.begin(); }

    iterator end() { return MultiMap.end(); }

    size_t size() { return MultiMap.size(); }

    bool empty() { return MultiMap.empty(); }

    void clear() { MultiMap.clear(); }

    void insert(const Pair<T, S> &elem) { MultiMap.insert(elem); }

    S &operator[](const T &index) {
        iterator tmp = MultiMap.find(Pair<T, S>(index, S()));
        if (tmp)
            return tmp.iter->data.second;
        else
            return MultiMap.insert(Pair<T, S>(index, S())).iter->data.second;
    }

    void insert(const T &first, const S &second) {
        insert(Pair<T, S>(first, second));
    }

    void erase(const T &first) {
        iterator tmp = MultiMap.find(Pair<T, S>(first, S()));
        MultiMap.erase(tmp);
    }
};

#endif
