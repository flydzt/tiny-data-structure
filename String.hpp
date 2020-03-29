#ifndef _STRING_HPP_
#define _STRING_HPP_

#include <iostream>
#include <cstdlib>
#include <cstring>

class String {
private:
    char *data;
    size_t total;
public:
    String(const size_t &n, const char &c) {
        total = n + 1;
        data = (char *) calloc(total, sizeof(char));
        memset(data, c, n);
    }

    String(const char *ptr = nullptr) {
        total = 1;
        if (ptr) {
            total = strlen(ptr) + 1;
            data = (char *) calloc(total, sizeof(char));
            strcpy(data, ptr);
        }
    }

    String(const String &rhs) {
        if (rhs.total > 1) {
            data = (char *) calloc(rhs.total, sizeof(char));
            total = rhs.total;
            strcpy(data, rhs.data);
        }
    }

    ~String() { if (total > 1)free(data); }

    String &operator=(const String &rhs) {
        if (this == &rhs)
            return *this;
        if (total > 1)
            free(data);
        total = rhs.total;
        data = (char *) calloc(total, sizeof(char));
        strcpy(data, rhs.data);
        return *this;
    }

    String &operator=(const char *ptr) {
        if (total > 1)
            free(data);
        total = 1;
        if (ptr) {
            total = strlen(ptr) + 1;
            data = (char *) calloc(total, sizeof(char));
            strcpy(data, ptr);
        }
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &, const String &);

    friend std::istream &operator>>(std::istream &, String &);

    String &operator+=(const String &rhs) {
        total += rhs.total - 1;
        char *newdata((char *) calloc(total, sizeof(char)));
        strcpy(newdata, data);
        strcat(newdata, rhs.data);
        if (total > 1)
            free(data);
        data = newdata;
        return *this;
    }

    String operator+(const String &rhs) {
        String tmp(data);
        tmp += rhs;
        return tmp;
    }

    char &operator[](const int &index) {
        return data[index];
    }

    bool operator<(const String &rhs) {
        if (this == &rhs)
            return false;
        size_t minlen = total < rhs.total ? total : rhs.total;
        for (size_t i = 0; i < minlen; ++i)
            if (data[i] < rhs.data[i])
                return true;
            else if (data[i] > rhs.data[i])
                return false;
            else
                continue;
        return total < rhs.total;
    }

    bool operator>(const String &rhs) {
        if (this == &rhs)
            return false;
        size_t minlen = total < rhs.total ? total : rhs.total;
        for (size_t i = 0; i < minlen; ++i)
            if (data[i] > rhs.data[i])
                return true;
            else if (data[i] < rhs.data[i])
                return false;
            else
                continue;
        return total > rhs.total;
    }

    bool operator==(const String &rhs) {
        if (this == &rhs)
            return true;
        if (total != rhs.total)
            return false;
        for (int i = 0; i < total; ++i) {
            if (data[i] != rhs.data[i])
                return false;
        }
        return true;
    }

    bool operator!=(const String &rhs) {
        return !this->operator==(rhs);
    }

    size_t size() { return total - 1; }

    const char *begin() { return &data[0]; }

    const char *end() { return data + total - 1; }

    bool operator>=(const String &rhs) {
        if (this == &rhs)
            return false;
        size_t minlen = total > rhs.total ? rhs.total : total;
        for (size_t i = 0; i < minlen; ++i)
            if (data[i] >= rhs.data[i])
                return true;
            else if (data[i] < rhs.data[i])
                return false;
            else
                continue;
        return total > rhs.total;
    }

    bool operator<=(const String &rhs) {
        if (this == &rhs)
            return false;
        size_t minlen = total > rhs.total ? rhs.total : total;
        for (size_t i = 0; i < minlen; ++i)
            if (data[i] <= rhs.data[i])
                return true;
            else if (data[i] > rhs.data[i])
                return false;
            else
                continue;
        return total > rhs.total;
    }
};

std::ostream &operator<<(std::ostream &output, const String &rhs) {
    output << rhs.data;
    return output;
}

std::istream &operator>>(std::istream &input, String &rhs) {
    char tmp[255];
    input >> tmp;
    rhs = /*(String)*/tmp;
    return input;
}

#endif

