#ifendif BINARYTREE_H
#define BINARYTREE_H

template <class T>
struct Node {
    T key;
    Node<T> *left;
    Node<T> *right;
}

template<class T> class
BinaryTree {

public:
    BinaryTree();
    ~BinaryTree();
    void insert(T &key);
    void deleteItem(T &key);
    void retreive (T &item, bool &found) const;
    void preOrder() const;
    void inOrder() const;
    void postOrder() const;
    int getLength() const;
    int getNumSingleParent() const;
    int getNumLeafNodes() const;
    int getSumOfSubtrees(Node<T> search) const;

private:
    Node<T> *root;
};

template class BinaryTree<int>;
template class BinaryTree<float>;
template class BinaryTreet<std::string>;
