#include "BinaryTree.h"
#include <iostream>
#include <string>

using namespace std;

template <class T>
BinaryTree<T>::BinaryTree() { //Constructor
    root = NULL;
} //Constructor end

template <class T>
BinaryTree<T>::~BinaryTree() { //Destructor
    destroy(root);
} //Destructor end

template <class T>
void BinaryTree<T>::destroy(Node<T>*& node) {
    if (node != NULL) {
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
} //destroy

template <class T>
void BinaryTree<T>::insert(T &key) { //Insert
    bool found = false;
    if (root == NULL) {
        root = new Node<T>();
        root->key = key;
    } else {
        retrieve(key, found) ;
        if (found == true) {
            cout << "Item already in tree." << endl;
        } else {
            addItem(root, key);
        } //if/else
    } //if/else
} //Insert end

template <class T>
void BinaryTree<T>::addItem(Node<T>*& t, T &key) {//addItem
    if (t == NULL) {
        t = new Node<T>();
        t->right = NULL;
        t->left = NULL;
        t->key = key;
    } else if (key < t->key) {
        addItem(t->left, key);
    } else if (key > t->key) {
        addItem(t->right, key);
    } //else/if
} //addItem

template <class T>
void BinaryTree<T>::deleteItem(T &key) { //DeleteItem
    deleteSearch(root, key);
} //DeleteItem

template <class T>
void BinaryTree<T>::deleteSearch(Node<T>*& node, T &key) { //DeleteSearch
    if (key < node->key) {
        deleteSearch(node->left, key);
    } else if (key > node->key) {
        deleteSearch(node->right, key);
    } else {
        deleteFound(node, key);
    }
} //DeleteSearch

template <class T>
void BinaryTree<T>::deleteFound(Node<T>*& node, T &key) { //DeleteFound
    Node<T>* tempNode;
    tempNode = node;
    if (node->left == NULL) {
        node = node->right;
        delete tempNode;
    } else if (node->right == NULL) {
        node = node->left;
        delete tempNode;
    } else {
        T val = getPredecessor(node->left);
        node->key = val;
        deleteSearch(node->left,val);
    } //if/else
} //DeleteFound

template <class T>
T BinaryTree<T>::getPredecessor(Node<T>* node) { //getPredecessor
    while(node->right != NULL) {
        node = node->right;
    }
    return node->key;
} //getPredecessor


template <class T>
void BinaryTree<T>::retrieve (T &item, bool &found) const { //Retreive
    getItem(item, found, root);
} //Retreive end

template <class T>
Node<T>* BinaryTree<T>::getItem (T &item, bool &found, Node<T>* tree) const { //GetItem
    if (tree == NULL) {
        found = false;
        return NULL;
    } else if (item < tree->key) {
        return getItem(item, found, tree->left);
    } else if (item > tree->key) {
        return getItem(item, found, tree->right);
    } else {
        found = true;
        return tree;
    } //else/if
} //getItem end

template <class T>
void BinaryTree<T>::preOrder() const { //PreOrder
    preOrderPrint(root);
} //PreOrder end

template <class T>
void BinaryTree<T>::preOrderPrint(Node<T>* node) const { //PreOrderPrint, written by Taylor
    if(node != NULL) {
        cout << node->key << " ";
        preOrderPrint(node->left);
        preOrderPrint(node->right);
    }
} //PreOrderPrint end

template <class T>
void BinaryTree<T>::inOrder() const { //InOrder
    inOrderPrint(root);
} //InOrder end

template <class T>
void BinaryTree<T>::inOrderPrint(Node<T>* node) const { // inOrderPrint, written by Taylor
    if(node != NULL) {
        inOrderPrint(node->left);
        cout << node-> key << " ";
        inOrderPrint(node->right);
    } // if
} // inOrderPrint end

template <class T>
void BinaryTree<T>::postOrder() const { // postOrder
    postOrderPrint(root);
} // postOrder end

template <class T>
void BinaryTree<T>::postOrderPrint(Node<T>* node) const { // postOrderPrint, written by Taylor
    if(node != NULL) {
        postOrderPrint(node->left);
        postOrderPrint(node->right);
        cout << node->key << " ";
    } // if
} // postOrderPrint end

template <class T>
int BinaryTree<T>::getLength() const { //GetLength
    return countNodes(root);
} //GetLength end

template <class T>
int BinaryTree<T>::countNodes(Node<T>* tree) const { //countNodes
    if (tree == NULL) {
        return 0;
    } else {
        return countNodes(tree->left) + countNodes(tree->right) + 1;
    } //if/else
} //countNodes end

template <class T>
int BinaryTree<T>::getNumSingleParent(Node<T>* node) const { // getNumSingleParent
    if (node == NULL) {
        return 0;
    } else {
        if (node->left == NULL && node->right != NULL) {
            return getNumSingleParent(node->right) + 1;
        } else if (node->left != NULL && node->right == NULL) {
            return getNumSingleParent(node->left) + 1;
        } else {
            return getNumSingleParent(node->left) + getNumSingleParent(node->right);
        }
    } // if/else
} // getNumSingleParent end

template <class T>
int BinaryTree<T>::getNumLeafNodes(Node<T>* node) const { //GetNumLeafNodes
    if(node == NULL) {
        return 0;
    } else {
        if (node->left == NULL && node->right == NULL) {
            return 1;
        } else {
            return getNumLeafNodes(node->left) + getNumLeafNodes(node->right);
        } //if/else
    } //if/else

} //GetNumLeafNodes end

template <class T>
T BinaryTree<T>::getSumOfSubtrees(Node<T>* search, bool first) const { //getSumOfSubtrees
    if (search == NULL) {
        if(is_same<T, string>::value) {
            return NULL;
        } else {
            return 0;
        }
    } else if (first) {
        return getSumOfSubtrees(search->right, false) + getSumOfSubtrees(search->left, false);
    } else {
        return search->key + getSumOfSubtrees(search->right, false) + getSumOfSubtrees(search->left, false);
    } //ifelse
} //getSumOfSubtreesEnd

template <class T>
Node<T>* BinaryTree<T>::getRoot() { //getRoot
    return root;
} //getRoot
