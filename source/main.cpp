#include <iostream>
#include "../header/vector.h"
#include "../header/linked_list.h"
#include "../header/binary_tree.h"

int main()
{
    BinTree tree(1);
    std::cout << tree.Find(1);

    // List<int> vec(5);
    // List<int> A = vec;
    // std::cout << (vec == A) << " " << vec.getSize() << std::endl;

    // vec.pushFront(10);
    // vec.popFront();

    // std::cout << (vec == A) << " " << vec.getSize() << std::endl;
    // std::cout << vec[1]<< std::endl;
    // std::cout << vec.Find(vec[1]->value) << std::endl;

    // vec.Resize(10);
    // vec.pushBack(-3.1);
    // vec.pushFront('h');
    // std::cout << vec << vec.getSize() << std::endl;

    
    // Vector<int> vec(100);
    // std::cout << vec << vec.getSize() << std::endl;
    // Vector<int> A = vec;

    // vec.Push(10);
    // std::cout << vec << vec.getSize() << std::endl;
    // vec.Pop();
    // std::cout << vec << vec.getSize() << std::endl;

    // std::cout << (vec == A) << " " << vec.getSize() << std::endl;
    // std::cout << vec[9] << std::endl;
    // std::cout << vec.Find(1) << std::endl;

    // vec.Resize(10);
    // vec.Push(-3.1);
    // vec.Push('h');
    // std::cout << vec << vec.getSize() << std::endl;

    return 0;
}
