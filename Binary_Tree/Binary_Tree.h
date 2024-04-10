#ifndef THE_SECOND_SEMESTER_BINARY_TREE_H
#define THE_SECOND_SEMESTER_BINARY_TREE_H

#include <iostream>

class BinaryTree
        {
public:
    class Node;
public:
    BinaryTree(const int key = 0);
    BinaryTree(const BinaryTree& other);
    ~BinaryTree();

    Node* getRoot() const {return m_root;};
    void clear();
    void clearFrom(const Node*);

    bool isEmpty() const {return m_root != nullptr;};
    Node* copy(const Node* other);
    int getHeight() const;

private:
    Node* m_root = nullptr;
};

class BinaryTree::Node
        {

public:
    Node(const int key = 0, Node* left = nullptr, Node* right = nullptr);
    int getKey() const {return m_key;}
    void setKey(const int key);

private:
    int m_key = 0;
    Node* m_left = nullptr;
    Node* m_right = nullptr;
};


#endif //THE_SECOND_SEMESTER_BINARY_TREE_H
