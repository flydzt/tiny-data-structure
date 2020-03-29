#ifndef _MAP_HPP_
#define _MAP_HPP_

#include "Pair.hpp"
#include "Skiplist.hpp"

template<typename T, typename S>
class Map {
public:
    typedef typename Skiplist<Pair<T, S>>::iterator iterator;
    typedef T first_type;
    typedef S second_type;
    typedef Pair<T, S> value_type;
    Skiplist<Pair<T, S>> map;

    iterator begin() { return map.begin(); }

    iterator end() { return map.end(); }

    size_t size() { return map.size(); }

    bool empty() { return map.empty(); }

    void clear() { map.clear(); }

    void insert(const Pair<T, S> &elem) {
        iterator tmp = map.find(Pair<T, S>(elem.first, S()));
        if (tmp.iter == nullptr)
            map.insert(elem);
        else
            tmp.iter->data.second = elem.second;
    }

    S &operator[](const T &index) {
        iterator tmp = map.find(Pair<T, S>(index, S()));
        if (tmp)
            return tmp.iter->data.second;
        else
            return map.insert(Pair<T, S>(index, S())).iter->data.second;
    }

    void insert(const T &first, const S &second) {
        iterator tmp = map.find(Pair<T, S>(first, S()));
        if (tmp == nullptr)
            insert(Pair<T, S>(first, second));
        else tmp.iter->data.second = second;
    }

    void erase(const T &first) {
        iterator tmp = map.find(Pair<T, S>(first, S()));
        map.erase(tmp);
    }
};

#endif
