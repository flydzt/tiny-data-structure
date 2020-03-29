#ifndef _DEQUEUE_HPP_
#define _DEQUEUE_HPP_


#include "List.hpp"

template<typename T>
class Dequeue {
protected:
    List<T> dequeue;
public:
    typedef typename List<T>::iterator iterator;

    Dequeue() {}

    Dequeue(const Dequeue &rhs) : dequeue(rhs.dequeue) {}

    size_t size() { return dequeue.size(); }

    bool empty() { return dequeue.empty(); }

    void clear() { dequeue.clear(); }

    iterator begin() { return dequeue.begin(); }

    iterator end() { return dequeue.end(); }

    Dequeue &operator=(const Dequeue &rhs) {
        dequeue = rhs.dequeue;
        return *this;
    }

    void push_back(const T &elem) {
        dequeue.push_back(elem);
    }

    void push_front(const T &elem) {
        dequeue.push_front(elem);
    }

    T pop_back() {
        T tmp = *(dequeue.end() - 1);
        dequeue.erase(dequeue.end() - 1);
        return tmp;
    }

    T pop_front() {
        T tmp = *(dequeue.begin());
        dequeue.erase(dequeue.begin());
        return tmp;
    }
};

#endif