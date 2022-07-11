#include "../header/binary_tree.h"

void BinTree::treeFill(int num)
{
    root = new TNode(rand());
    for (int i = 0; i < num; i++)
        push(rand());
}
void BinTree::deleteTree(TNode *curr)
{
    if (curr)
    {
        deleteTree(curr->left);
        deleteTree(curr->right);
        delete curr;
    }
}
void BinTree::printTree(TNode *curr)
{
    if (curr)
    {
        printTree(curr->left);
        printTree(curr->right);
        std::cout << curr->value << " ";
    }
}

void BinTree::copy(TNode *curr)
{
    if (curr)
    {
        push(curr->value);
        copy(curr->left);
        copy(curr->right);
    }
}
bool BinTree::equal(TNode *curr)
{
    if (curr)
    {
        TNode *temp = root;
        if (temp->value != curr->value)
            return false;
        copy(curr->left);
        copy(curr->right);
    }
    return true;
}
