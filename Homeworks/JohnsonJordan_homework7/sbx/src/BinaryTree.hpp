#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

template <typename T>
class BinaryTree {
    public:
        // default constructor
        BinaryTree() { }

        // destructor
        virtual ~BinaryTree() { }

        // return the left subtree
        virtual BinaryTree* getLeft() const = 0;

        // return the right subtree
        virtual BinaryTree* getRight() const = 0;

        // return the value of the root
        virtual T getValue() const = 0;

        // find the height of the binary tree
        virtual int height() const = 0;

        // determine if the binary tree is a leaf node
        virtual bool isLeaf() const = 0;

        // find the number of leaves in the binary tree
        virtual int numLeaves() const = 0;

        // find the number of nodes in the binary tree
        virtual int numNodes() const = 0;

        // update the left subtree
        virtual void setLeft(BinaryTree*) = 0;

        // update the right subtree
        virtual void setRight(BinaryTree*) = 0;

        // update the value of the root
        virtual void setValue(const T&) = 0; 
};

#endif
