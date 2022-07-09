//#pragma once
#include <random>
#include <cstring>

template <class T>
class Vector
{
private:
    T *arr;
    int size;     // amount of non-zero values of vector
    int capacity; // actural size of vector

public:
    Vector(int _size = 0) : arr(nullptr), size(_size), capacity(_size)
    {
        arr = new T[capacity];
        for (int i = 0; i < size; i++)
        {
            arr[i] = rand();
        }
    };
    Vector(const Vector &cpy)
    {
        this->size = cpy.size;
        this->capacity = cpy.capacity;
        this->arr = new T[capacity];
        for (int i = 0; i < size; i++)
        {
            this->arr[i] = cpy.arr[i];
        }
    };
    ~Vector() { delete[] arr; };

    Vector &operator=(const Vector &eq)
    {
        this->size = eq.size;
        this->capacity = eq.capacity;
        this->arr = new T[capacity];

        for (int i = 0; i < size; i++)
        {
            this->arr[i] = eq.arr[i];
        }
    };
    bool operator==(const Vector &eq)
    {
        if (this->size != eq.size)
            return false;
        else
            for (int i = 0; i < size; i++)
                if (this->arr[i] != eq.arr[i])
                    return false;
        return true;
    };
    T &operator[](int ind)
    {
        if (ind < size && ind >= 0)
            return arr[ind];
        throw("out of range");
    };

    int getSize() { return size; };
    void Resize(int newcap)
    {
        if (newcap < 0)
            throw("wrong capacity");
        T *temp = new T[capacity];
        memcpy(temp, arr, capacity * sizeof(T));
        arr = new T[newcap];
        memcpy(arr, temp, ((newcap < capacity) ? newcap : capacity) * sizeof(T));
        capacity = newcap;
        if (newcap < size)
            size = newcap;
        delete[] temp;
    };
    void Push(T input)
    {
        if (size == capacity)
            Resize(capacity + 10);
        arr[size++] = input;
    };
    void Pop()
    {
        if (size != 0)
            this->Resize(capacity - 1);
        else
            throw("vector is empty");
    };
    int Find(T val)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == val)
                return i;
        }
        return INT32_MIN;
    };
    // void Print()
    // {
    //     for (int i = 0; i < size; i++)
    //     {
    //         std::cout << arr[i] << " ";
    //     }
    //     std::cout << std::endl;
    // };

    template <class U>
    friend std::ostream &operator<<(std::ostream &strm, const Vector<U> &vec);
};

template <class U>
std::ostream &operator<<(std::ostream &strm, const Vector<U> &vec)
{
    strm << '[';
    for (int i = 0; i < vec.size - 1; i++)
    {
        strm << vec.arr[i] << " ";
    }
    strm << vec.arr[vec.size - 1] << ']';

    return strm;
}
