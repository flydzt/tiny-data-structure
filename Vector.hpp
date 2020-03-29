#ifndef _VECTOR_HPP_
#define _VECTOR_HPP_


#include <cstring>
#include <cstdlib>


template<typename T>
class Vector {
public:
    typedef T *iterator;
protected:
    iterator head;
    size_t used;
    size_t total;
public:
    Vector() :
            head(nullptr), used(0), total(1) {}

    Vector(const int &n, const T &t = T()) {
        total = n + 1;
        used = n;
        head = (iterator) malloc(total * sizeof(T));
        for (size_t i = 0; i < used; ++i) {
            *(head + i) = t;
        }
    }

    Vector(const Vector &rhs) {
        head = (iterator) malloc(rhs.total * sizeof(T));
        memcpy(head, rhs.head, rhs.total * sizeof(T));
        used = rhs.used;
        total = rhs.total;
    }

    template<typename S>
    Vector(S begin, S end) {
        used = 0;
        for (S i = begin; i != end; ++i)
            ++used;
        total = used + 1;
        head = (iterator) malloc(total * sizeof(T));
        size_t index = 0;
        for (S i = begin; i != end; ++i) {
            *(head + index) = *i;
            ++index;
        }
    }

    Vector(T *begin, T *end) {
        used = end - begin;
        total = used + 1;
        head = (iterator) malloc(total * sizeof(T));
        memcpy(head, begin, used * sizeof(T));
    }

    ~Vector() {
        clear();
        if (total > 1)
            free(head);
    }

    Vector &operator=(const Vector<T> &rhs) {
        if (this == &rhs)
            return *this;
        destroy();
        used = rhs.used;
        total = rhs.total;
        head = (iterator) malloc(total * sizeof(T));
        memcpy(head, rhs.head, used * sizeof(T));
        return *this;
    }

    iterator begin() { return head; }

    T front() { return *begin(); }

    iterator end() { return head + used; }

    T back() { return *(head + used - 1); }

    size_t size() { return used; }

    size_t capacity() { return total - 1; }

    bool empty() { return used == 0; }

    T &operator[](const size_t &index) {
        return *(head + index);
    }

    void push_back(const T &elem) {
        insert(head + used, elem);
    }

    void clear() {
        if (used == 0)
            return;
        for (size_t i = 0; i < used; ++i)
            (head + i)->~T();
        used = 0;
    }

    T pop_back() {
        if (used) {
            --used;
            T tmp = *(head + used);
            (head + used)->~T();
            return tmp;
        }
        return T();
    }

    void erase(iterator index) {
        index->~T();
        for (iterator i(index); i != end(); ++i)
            *i = *(i + 1);
        --used;
    }

    void insert(iterator index, const T &elem) {
        if (total - used > 1) {
            for (iterator i(end()); i != index; --i)
                *i = *(i - 1);
            *index = elem;
            ++used;
        } else {
            if (total == 1)
                total = 2;
            else
                total = total * 2 - 1;
            iterator newhead((iterator) calloc(total, sizeof(T)));
            memcpy(newhead, head, (index - head) * sizeof(T));
            *(newhead + (index - head)) = elem;
            memcpy(newhead + (index - head) + 1, index, (used - (index - head)) * sizeof(T));
            for (int i = 0; i < used; ++i)
                (head + i)->~T();
            free(head);
            head = newhead;
            ++used;
        }
    }

    void destroy() {
        clear();
        if (total > 1)
            free(head);
        head = nullptr;
        used = 0;
        total = 1;
    }
};

#endif
