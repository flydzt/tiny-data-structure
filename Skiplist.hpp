#ifndef _SKIPLIST_HPP_
#define _SKIPLIST_HPP_

#include "Vector.hpp"

template<typename T>
class Skiplist_node {
public:
    int level;
    Vector<Skiplist_node<T> *> next;
    Vector<Skiplist_node<T> *> prev;
    T data;
};

template<typename T>
class Skiplist_Iterator {
public:
    typedef Skiplist_node<T> *node_ptr;
    typedef Skiplist_Iterator self;
    node_ptr iter;


    Skiplist_Iterator(const node_ptr _ptr = nullptr) : iter(_ptr) {}

    Skiplist_Iterator(const self &_iter) : iter(_iter.iter) {}

    T operator*() { return iter->data; }

    node_ptr operator->() { return iter; }

    bool operator==(const self &rhs) {
        return iter == rhs.iter;
    }

    bool operator!=(const self &rhs) {
        return iter != rhs.iter;
    }

    int level() {
        return iter->level;
    }

    self operator++() {
        if (iter == nullptr)
            return nullptr;
        iter = iter->next[0];
        return iter;
    }

    self operator++(int) {
        self tmp(tmp);
        if (iter->next[0])
            iter = iter->next[0];
        return tmp;
    }

    operator int() {
        if (iter)
            return 1;
        else
            return 0;
    }
};

template<typename T>
class Skiplist {
public:
    typedef Skiplist_Iterator<T> iterator;
    typedef Skiplist_node<T> node_type;
    iterator head;
    size_t total;
    const static int maxlevel = 32;

    iterator begin() { return head->next[0]; }

    iterator end() { return nullptr; }

    Skiplist() : total(0) {
        head = (node_type *) calloc(1, sizeof(node_type));
        head->level = maxlevel;
        head->next = Vector<node_type *>(head->level, nullptr);
        head->prev = Vector<node_type *>(head->level, nullptr);
    }

    void clear() {
        if (total == 0)
            return;
        total = 0;
        iterator i(head->next[0]);
        iterator j;
        while (i.iter) {
            j = i->next[0];
            i->~Skiplist_node();
            free(i.iter);
            i.iter = nullptr;
            i = j;
        }
        for (int i = 0; i < maxlevel; ++i)
            head->next[i] = nullptr;
    }

    ~Skiplist() {
        clear();
        head->~Skiplist_node();
        free(head.iter);
        head.iter = nullptr;
    }

    size_t size() { return total; }

    size_t empty() { return total == 0; }

    iterator insert(const T &elem) {
        ++total;
        iterator tmp;
        tmp = (node_type *) calloc(1, sizeof(node_type));

        tmp->data = elem;
        tmp->level = 1;
        while (rand() % 2)
            ++tmp->level;
        if (tmp->level > maxlevel)
            tmp->level = maxlevel;
        tmp->next = Vector<node_type *>(tmp->level, nullptr);
        tmp->prev = Vector<node_type *>(tmp->level, nullptr);
        iterator i(head);
        for (int cur_level = tmp->level - 1; cur_level >= 0; --cur_level) {
            if (i->next[cur_level] == nullptr) {
                i->next[cur_level] = tmp.iter;
                tmp->prev[cur_level] = i.iter;
            } else if ((i->next[cur_level]->data) > tmp->data) {
                tmp->next[cur_level] = i->next[cur_level];
                tmp->prev[cur_level] = i.iter;
                i->next[cur_level]->prev[cur_level] = tmp.iter;
                i->next[cur_level] = tmp.iter;
            } else if (i->next[cur_level]->data <= tmp->data) {
                i = i->next[cur_level];
                ++cur_level;
            }
        }
        return tmp;
    }

    iterator find(const T &elem) {
        iterator cur(head);
        for (int i = maxlevel - 1; i >= 0; --i) {
            if (cur->next[i]) {
                if (cur->next[i]->data < elem) {
                    cur = cur->next[i];
                    ++i;
                } else if (cur->next[i]->data == elem)
                    return cur->next[i];
            }
        }
        return nullptr;
    }

    void erase(const T &elem) {
        iterator tmp = find(elem);
        erase(tmp);
    }

    void erase(iterator index) {
        if (index.iter == nullptr)
            return;
        --total;
        for (int i = 0; i < index.level(); ++i) {
            if (index->next[i] != nullptr)
                index->next[i]->prev[i] = index->prev[i];
            index->prev[i]->next[i] = index->next[i];
        }
        index->~Skiplist_node();
        free(index.iter);
        index.iter = nullptr;
    }
};

#endif
