#include <iostream>

#include "BinaryTree.hpp"

int main()
{
    int n;
    std::cout << "Enter the root of the binary tree: " << std::endl;
    std::cin >> n;
    BinaryTree* t = new BinaryTree(n);
    std::cout << "Enter the node values in level-order traversal: " << std::endl;
    while (n)
    {
        std::cin >> n;
        if (n) t->add(n);
    }
    std::cout << "Your binary tree: " << std::endl;
    t->print();
    std::cout << "\nEnter the value that should be removed: " << std::endl;
    std::cin >> n;
    t = t->remove(n);
    std::cout << "Your binary tree again: " << std::endl;
    t->print();
    return 0;
}