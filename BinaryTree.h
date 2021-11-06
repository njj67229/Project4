#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <string>

template <class T>
struct Node {
    T key;
    Node<T>* left;
    Node<T>* right;
};

template<class T> class BinaryTree {

public:
    BinaryTree();
    ~BinaryTree();
    void destroy(Node<T>*& node);
    void insert(T &key);
    void addItem(Node<T>*& t, T &key);
    void deleteItem(T &key);
    void deleteSearch(Node<T>*& node, T &key);
    void deleteFound(Node<T>*& node, T &key);
    T getPredecessor(Node<T>* node);
    void retrieve (T &item, bool &found) const;
    Node<T>* getItem(T &item, bool &found, Node<T>* tree) const;
    void preOrder() const;
    void preOrderPrint(Node<T>* node) const;
    void inOrder() const;
    void inOrderPrint(Node<T>* node) const;
    void postOrder() const;
    void postOrderPrint(Node<T>* node) const;
    int getLength() const;
    int countNodes(Node<T>* tree) const;
    int getNumSingleParent(Node<T>* node) const;
    int getNumLeafNodes(Node<T>* node) const;
    T getSumOfSubtrees(Node<T>* search, bool first) const;
    Node<T>* getRoot();
private:
    Node<T>* root;
    int length;
};

template class BinaryTree<int>;
template class BinaryTree<float>;
template class BinaryTree<std::string>;

#endif
