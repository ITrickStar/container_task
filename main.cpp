#include <iostream>
#include "./header/vector.h"

int main()
{
    Vector<int> vec(10);
    std::cout << vec.Find(1);

    // //vec.Resize(10);
    // std::cout << vec << vec.getSize();

    // vec.Push(3.1);
    // std::cout << vec << vec.getSize();

    return 0;
}
