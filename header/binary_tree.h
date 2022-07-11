#include <iostream>

struct TNode
{
    int value;
    TNode *left;
    TNode *right;
    TNode(int _value = 0) : left(nullptr), right(nullptr), value(_value) {}
};

class BinTree
{
private:
    TNode *root;
    int size;

    void treeFill(int num);
    void deleteTree(TNode *curr);
    void printTree(TNode *curr);
    void copy(TNode *curr);
    bool equal(TNode *curr);

public:
    BinTree(int num = 1) : size(num) { treeFill(num); }
    BinTree(const BinTree *eq)
    {
        deleteTree(root);
        root = new TNode();
        treeFill(eq->size);
        copy(eq->root);
    }
    ~BinTree() { deleteTree(root); }

    BinTree &operator=(const BinTree &eq)
    {
        deleteTree(root);
        root = new TNode();
        treeFill(eq.size);
        copy(eq.root);
        return *this;
    }
    bool operator==(const BinTree &eq)
    {
        if (this->size != eq.size)
            return false;
        else
            return equal(eq.root);
    }

    void print()
    {
        printTree(root);
        std::cout << std::endl;
    }
    bool find(int input)
    {
        TNode *curr = root;
        while (curr && curr->value != input)
        {
            if (curr->value > input)
                curr = curr->left;
            else
                curr = curr->right;
        }
        return curr != nullptr;
    }
    void push(int input)
    {
        TNode *curr = root;
        while (curr && curr->value != input)
        {
            if (curr->value > input && curr->left == nullptr)
            {
                curr->left = new TNode(input);
                size++;
                return;
            }
            if (curr->value < input && curr->right == nullptr)
            {
                curr->right = new TNode(input);
                size++;
                return;
            }
            if (curr->value > input)
                curr = curr->left;
            else
                curr = curr->right;
        }
    }

    void pop(int input)
    {
        TNode *curr = root;
        TNode *parent = nullptr;
        while (curr && curr->value != input)
        {
            parent = curr;
            if (curr->value > input)
            {
                curr = curr->left;
            }
            else
            {
                curr = curr->right;
            }
        }
        if (!curr)
            return;
        if (curr->left == nullptr)
        {
            if (parent && parent->left == curr)
                parent->left = curr->right;
            if (parent && parent->right == curr)
                parent->right = curr->right;
            size--;
            delete curr;
            return;
        }
        if (curr->right == nullptr)
        {
            if (parent && parent->left == curr)
                parent->left = curr->left;
            if (parent && parent->right == curr)
                parent->right = curr->left;
            --size;
            delete curr;
            return;
        }

        TNode *replace = curr->right;
        while (replace->left)
            replace = replace->left;
        int sum = replace->value;
        pop(sum);
        curr->value = sum;
    }
    int getSize() { return size; };
};
