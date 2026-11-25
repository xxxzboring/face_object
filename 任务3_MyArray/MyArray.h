#ifndef MYARRAY_H
#define MYARRAY_H

class MyArray {
public:
    MyArray();
    MyArray(int n, int value = 0);
    MyArray(const MyArray &other);
    ~MyArray();

    int size() const;
    int get(int index) const;
    void set(int index, int value);
    void display() const;

    MyArray merge(const MyArray &other) const;
    MyArray add(const MyArray &other) const;
    MyArray subtract(const MyArray &other) const;
    MyArray multiply(const MyArray &other) const;
    MyArray divide(const MyArray &other) const;

private:
    int *p;
    int N;

    static int shorterSize(const MyArray &a, const MyArray &b);
};

#endif
