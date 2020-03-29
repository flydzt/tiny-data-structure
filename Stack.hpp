#ifndef _STACK_HPP_
#define _STACK_HPP_

#include "Vector.hpp"

template<typename T>
class Stack {
private:
    Vector<T> stack;
public:
    typedef typename Vector<T>::iterator iterator;

    ~Stack() { stack.~Vector(); }

    iterator begin() { return stack.begin(); }

    iterator end() { return stack.end(); }

    size_t size() { return stack.size(); }

    size_t capacity() { return stack.capacity(); }

    bool empty() { return stack.empty(); }

    void clear() { stack.clear(); }

    T &push_back(const T &elem) {
        return stack.push_back(elem);
    }

    T pop_back() {
        return stack.pop_back();
    }
};

#endif
