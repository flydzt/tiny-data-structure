#ifndef _PAIR_HPP_
#define _PAIR_HPP_

template<typename T, typename S>
class Pair {
public:
    T first;
    S second;
public:
    Pair() : first(T()), second(S()) {}

    template<typename U, typename V>
    Pair(const U &_first, const V &_second):first(_first), second(_second) {}

    template<typename U, typename V>
    Pair(const Pair<U, V> &rhs): first(rhs.first), second(rhs.second) {}

    template<typename U, typename V>
    Pair<T, S> &operator=(const Pair<U, V> &rhs) {
        first = rhs.first;
        second = rhs.second;
    }

    bool operator<(const Pair<T, S> &rhs) { return first < rhs.first; }

    bool operator>(const Pair<T, S> &rhs) { return first > rhs.first; }

    bool operator==(const Pair<T, S> &rhs) { return first == rhs.first; }

    bool operator>=(const Pair<T, S> &rhs) { return first >= rhs.first; }

    bool operator<=(const Pair<T, S> &rhs) { return first <= rhs.first; }

    bool operator!=(const Pair<T, S> &rhs) { return first != rhs.first; }
};

template<typename T, typename S>
Pair<T, S> Make_pair(const T &first, const S &second) {
    return Pair<T, S>(first, second);
}

template<typename T, typename S>
Pair<T *, S> Make_pair(T *first, const S &second) {
    return Pair<T *, S>(first, second);
}

template<typename T, typename S>
Pair<T, S *> Make_pair(const T &first, S *second) {
    return Pair<T, S *>(first, second);
}

template<typename T, typename S>
Pair<T *, S *> Make_pair(T *first, S *second) {
    return Pair<T *, S *>(first, second);
}

#endif
