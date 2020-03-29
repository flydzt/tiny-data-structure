#ifndef _QUEUE_HPP_
#define _QUEUE_HPP_

#include "List.hpp"

template<typename T>
class Queue {
private:
    List<T> queue;
public:
    typedef typename List<T>::iterator iterator;

    void push(const T &elem) { queue.push_back(elem); }

    iterator begin() { return queue.begin(); }

    T &front() { return *begin(); }

    T &back() { return *(end() - 1); }

    iterator end() { return queue.end(); }

    size_t size() { return queue.size(); }

    bool empty() { return queue.empty(); }

    void clear() { queue.clear(); }

    T pop() {
        if (size() == 0)
            return T();
        T tmp = *(queue.begin());
        queue.erase(queue.begin());
        return tmp;
    }
};

#endif
