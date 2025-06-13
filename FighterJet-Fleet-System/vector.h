#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
using namespace std;

template <typename T>

class Vector {
private:
    T* arr;
    int len;
    int cap;

    void double_capacity() {
        if (cap == 0) {
            cap = 1;
        }
        reserve(cap * 2);
    }

public:
    Vector() : arr(new T[1]), len(0), cap(1) {}

    Vector(int count, const T& value) : arr(new T[count]), len(count), cap(count) {
        for (int i = 0; i < count; ++i)
            arr[i] = value;
    }

    Vector(const Vector& other) : arr(new T[other.cap]), len(other.len), cap(other.cap) {
        for (int i = 0; i < len; ++i)
            arr[i] = other.arr[i];
    }

    ~Vector() {
        delete[] arr;
    }

    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] arr;
            len = other.len;
            cap = other.cap;
            arr = new T[cap];
            for (int i = 0; i < len; ++i)
                arr[i] = other.arr[i];
        }
        return *this;
    }

    T& operator[](int index) {
        return arr[index];
    }

    const T& operator[](int index) const {
        return arr[index];
    }

    bool operator==(const Vector& other) const {
        if (len != other.len) {
            return false;
        }
        for (int i = 0; i < len; ++i)
            if (!(arr[i] == other.arr[i])) {
                return false;
            }
        return true;
    }

    bool operator!=(const Vector& other) const {
        if (len != other.len) {
            return true;
        }
        for (int i = 0; i < len; i++) {
            if (arr[i] != other.arr[i]) {
                return true;
            }
        }
        return false;
    }

    Vector operator+(const Vector& other) const {
        if (other.len == len) {
            Vector result(*this);
            for (int i = 0; i < len; i++) {
                result.arr[i] += other.arr[i];
            }
            return result;
        }
        else {
            cout << "Error!";
            return *this;
        }
    }

    Vector& operator+=(const Vector& other) {
        if (other.len == len) {
            for (int i = 0; i < len; i++) {
                this->arr[i] += other.arr[i];
            }
        }
        else {
            cout << "Error!";
        }
        return *this;
    }

    template <typename... Args>
    void emplace_back(Args... args) {
        if (len == cap) {
            double_capacity();
        }
        arr[len++] = T(args...);
    }

    void push(const T& value) {
        if (len == cap) {
            double_capacity();
        }
        arr[len] = value;
        len++;
    }

    void pop() {
        if (len > 0)
            len--;
    }

    T* begin() {
        return arr;
    }

    T* end() {
        return arr + len;
    }
    const T* begin() const {
        return arr;
    }

    const T* end() const {
        return arr + len;
    }

    void insert_at(int index, const T& value) {
        if (len == cap) {
            double_capacity();
        }
        for (int i = len - 1; i >= index; i--) {
            arr[i + 1] = arr[i];
        }
        arr[index] = value;
        len++;
    }

    void delete_at(int index) {
        if (index < 0 || index >= len) return;
        for (int i = index; i < len - 1; i++) {
            arr[i] = arr[i + 1];
        }
        len--;
    }

    void reserve(int newcap) {
        if (newcap <= cap) {
            return;
        }
        T* newarr = new T[newcap];
        for (int i = 0; i < len; ++i) {
            newarr[i] = arr[i];
        }
        delete[] arr;
        arr = newarr;
        cap = newcap;
    }

    void clear() {
        delete[] arr;
        cap = 1;
        arr = new T[cap];
        len = 0;
    }

    void swap(Vector& other) {
        Vector temp;
        temp = *this;
        *this = other;
        other = temp;
    }

    void shrink_to_fit() {
        if (cap > len) {
            T* newarr = new T[len];
            for (int i = 0; i < len; i++) {
                newarr[i] = arr[i];
            }
            delete[] arr;
            arr = newarr;
            cap = len;
        }
    }

    void reverse() {
        for (int i = 0; i < len / 2; i++) {
            T temp = arr[i];
            arr[i] = arr[len - i - 1];
            arr[len - i - 1] = temp;
        }
    }

    bool empty() const {
        return len == 0;
    }

    int size() const {
        return len;
    }

    T& at(int index) {
        return arr[index];
    }

    const T& at(int index) const {
        return arr[index];
    }

    T& front() {
        return arr[0];
    }

    const T& front() const {
        return arr[0];
    }

    T& back() {
        return arr[len - 1];
    }

    const T& back() const {
        return arr[len - 1];
    }

    int find(const T& value) const {
        for (int i = 0; i < len; ++i)
            if (arr[i] == value)
                return i;
        return -1;
    }

    void print() const {
        cout << "Array : " << endl;
        for (int i = 0; i < len; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

#endif
