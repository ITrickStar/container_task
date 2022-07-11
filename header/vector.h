//#pragma once
#include <random>
#include <cstring>

template <class T>
class Vector
{
private:
    T* arr;       // an array of data
    int size;     // amount of non-zero values of vector
    int capacity; // actal size of vector
    // func to fill the vector on default run
    void vecFill()
    {
        for (int i = 0; i < size; i++)
            arr[i] = rand();
    }

public:
    // default constructor
    Vector(int _size = 0) : arr(nullptr), size(_size), capacity(_size)
    {
        arr = new T[capacity];
        vecFill();
    };
    // copy constructor
    Vector(const Vector& cpy)
    {
        this->operator=(cpy);
    };
    ~Vector() { delete[] arr; };

    Vector& operator=(const Vector& eq)
    {
        this->size = eq.size;
        this->capacity = eq.capacity;
        this->arr = new T[capacity];

        for (int i = 0; i < size; i++)
            this->arr[i] = eq.arr[i];

        return *this;
    };
    // checks if every cells of same index are equal
    bool operator==(const Vector& eq)
    {
        if (this->size != eq.size)
            return false;
        else
            for (int i = 0; i < size; i++)
                if (this->arr[i] != eq.arr[i])
                    return false;

        return true;
    };
    T& operator[](int ind)
    {
        if (ind < size && ind >= 0)
            return arr[ind];
        throw("out of range");
    };

    int getSize() { return size; };
    // utility function to allocate extra space in a vector
    void resize(int newcap)
    {
        if (newcap < 0)
            throw("wrong capacity");

        T* temp = new T[capacity];
        memcpy(temp, arr, capacity * sizeof(T));
        arr = new T[newcap];
        memcpy(arr, temp, ((newcap < capacity) ? newcap : capacity) * sizeof(T));
        capacity = newcap;

        if (newcap < size)
            size = newcap;
        delete[] temp;
    };
    // func to change value located in ind position
    void chgValue(int ind, T input)
    {
        if (size)
            throw("vector is empty");
        if (ind > size)
            throw("out of range");
        else
            arr[ind] = input;
    };
    // pushes value in the end of an array
    // if it lacks of space Resize() function called
    void push(T input)
    {
        if (size == capacity)
            resize(capacity + 10);
        arr[size++] = input;
    };
    // erases value in the end of an array
    // actually there is no deletion only size variable decreased by 1
    void pop()
    {
        if (size != 0)
            size--;
        else
            throw("vector is empty");
    };
    int find(T val)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == val)
                return i;
        }
        return INT32_MIN;
    };

    template <class U>
    friend std::ostream& operator<<(std::ostream& strm, const Vector<U>& vec);
};

// output of a vector's content
// [1, 2, 3]
template <class U>
std::ostream& operator<<(std::ostream& strm, const Vector<U>& vec)
{
    strm << '[';
    for (int i = 0; i < vec.size - 1; i++)
    {
        strm << vec.arr[i] << " ";
    }
    strm << vec.arr[vec.size - 1] << ']';

    return strm;
}
