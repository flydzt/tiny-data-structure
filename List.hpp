#ifndef _LIST_HPP_
#define _LIST_HPP_

#include <cstdlib>

template<typename T>
class List_node {
public:
    List_node<T> *prev;
    List_node<T> *next;
    T data;

    List_node() : prev(nullptr), next(nullptr), data(T()) {}
};

template<typename T>
class List_Iterator {
public:
    typedef List_node<T> *nodeiter;
    typedef List_Iterator<T> self;
    List_node<T> *iter;
public:
    List_Iterator() : iter(nullptr) {}

    List_Iterator(const nodeiter rhs) {
        iter = rhs;
    }

    List_Iterator(const self &rhs) {
        iter = rhs.iter;
    }

    self &operator=(const nodeiter rhs) {
        iter = rhs;
        return *this;
    }

    self &operator=(const self &rhs) {
        iter = rhs.iter;
        return *this;
    }

    self operator++() {
        if (iter == nullptr)
            return nullptr;
        iter = iter->next;
        return iter;
    }

    self operator++(int) {
        self tmp = iter;
        if (iter == nullptr)
            return nullptr;
        iter = iter->next;
        return tmp;
    }

    self operator+(const size_t &rhs) {
        self tmp(*this);
        for (size_t i = 0; i < rhs; ++i)
            tmp.iter = tmp.iter->next;
        return tmp;
    }

    self operator-(const size_t &rhs) {
        self tmp(*this);
        for (size_t i = 0; i < rhs; ++i)
            tmp.iter = tmp.iter->prev;
        return tmp;
    }

    bool operator==(const self rhs) {
        return iter == rhs.iter;
    }

    bool operator!=(const self rhs) {
        return !(operator==(rhs));
    }

    nodeiter &operator->() {
        return iter;
    }

    T &operator*() {
        return iter->data;
    }
};

template<typename T>
class List {
public:
    typedef List_Iterator<T> iterator;
protected:
    iterator head;
    size_t total;
public:
    List() {
        total = 0;
        head = (List_node<T> *) malloc(sizeof(List_node<T>));
        head->prev = head.iter;
        head->next = head.iter;
    }

    List(const List &rhs) {
        List();
        for (iterator i = rhs.begin(); i != rhs.end(); ++i)
            push_back(*i);
    }

    void clear() {
        iterator i(head->next);
        while (i != head) {
            iterator j(i);
            j = j->next;
            i->~List_node();
            free(i.iter);
            i = j;
        }
        head->next = head.iter;
        head->prev = head.iter;
    }

    ~List() {
        clear();
        free(head.iter);
    }

    void insert(iterator index, const T &elem) {
        ++total;
        iterator tmp((List_node<T> *) malloc(sizeof(List_node<T>)));
        tmp->data = elem;
        tmp->next = index.iter;
        tmp->prev = index->prev;
        index->prev->next = tmp.iter;
        index->prev = tmp.iter;
    }

    void erase(iterator index) {
        index->prev->next = index->next;
        index->next->prev = index->prev;
        index.iter->~List_node();
        free(index.iter);
    }

    void reverse() {
        iterator i(begin());
        while (i != end()) {
            List_node<T> *tmp = i->next;
            i->next = i->prev;
            i->prev = tmp;
            i = i->prev;
        }
        List_node<T> *tmp = head.iter;
        head->next = head->prev;
        head->prev = tmp;
    }

    iterator begin() { return head->next; }

    iterator end() { return head; }

    size_t size() { return total; }

    size_t empty() { return total == 0; }

    void push_back(const T &elem) { insert(head, elem); }

    void push_front(const T &elem) { insert(begin(), elem); }
};

#endif
