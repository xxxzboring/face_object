#include "MyArray.h"

#include <iostream>

using namespace std;

MyArray::MyArray() : p(0), N(0)
{
}

MyArray::MyArray(int n, int value) : p(0), N(0)
{
    if (n <= 0) {
        cout << "Warning: size must be positive, created an empty array" << endl;
        return;
    }
    p = new int[n];
    N = n;
    for (int i = 0; i < N; ++i)
        p[i] = value;
}

MyArray::MyArray(const MyArray &other) : p(0), N(0)
{
    N = other.N;
    if (N > 0) {
        p = new int[N];
        for (int i = 0; i < N; ++i)
            p[i] = other.p[i];
    }
}

MyArray::~MyArray()
{
    delete[] p;
    p = 0;
    N = 0;
}

int MyArray::size() const
{
    return N;
}

int MyArray::get(int index) const
{
    if (index < 0 || index >= N) {
        cout << "Error: index " << index << " out of range, return 0" << endl;
        return 0;
    }
    return p[index];
}

void MyArray::set(int index, int value)
{
    if (index < 0 || index >= N) {
        cout << "Error: index " << index << " out of range, ignored" << endl;
        return;
    }
    p[index] = value;
}

void MyArray::display() const
{
    cout << "{";
    for (int i = 0; i < N; ++i) {
        if (i > 0)
            cout << ", ";
        cout << p[i];
    }
    cout << "}";
}

int MyArray::shorterSize(const MyArray &a, const MyArray &b)
{
    if (a.N != b.N) {
        cout << "Warning: different sizes (" << a.N << " vs " << b.N
             << "), use the shorter one" << endl;
    }
    return a.N < b.N ? a.N : b.N;
}

MyArray MyArray::merge(const MyArray &other) const
{
    MyArray result(N + other.N);
    int k = 0;
    for (int i = 0; i < N; ++i)
        result.p[k++] = p[i];
    for (int i = 0; i < other.N; ++i)
        result.p[k++] = other.p[i];
    return result;
}

MyArray MyArray::add(const MyArray &other) const
{
    int n = shorterSize(*this, other);
    MyArray result(n);
    for (int i = 0; i < n; ++i)
        result.p[i] = p[i] + other.p[i];
    return result;
}

MyArray MyArray::subtract(const MyArray &other) const
{
    int n = shorterSize(*this, other);
    MyArray result(n);
    for (int i = 0; i < n; ++i)
        result.p[i] = p[i] - other.p[i];
    return result;
}

MyArray MyArray::multiply(const MyArray &other) const
{
    int n = shorterSize(*this, other);
    MyArray result(n);
    for (int i = 0; i < n; ++i)
        result.p[i] = p[i] * other.p[i];
    return result;
}

MyArray MyArray::divide(const MyArray &other) const
{
    int n = shorterSize(*this, other);
    MyArray result(n);
    for (int i = 0; i < n; ++i) {
        if (other.p[i] == 0) {
            cout << "Warning: divisor at index " << i
                 << " is 0, the result is set to 0" << endl;
            result.p[i] = 0;
        } else {
            result.p[i] = p[i] / other.p[i];
        }
    }
    return result;
}
