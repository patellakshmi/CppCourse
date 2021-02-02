//
// Created by Lakshmi S Patel on 03/02/21.
//

#ifndef CPPCOURSE_BINARYTREE_H
#define CPPCOURSE_BINARYTREE_H

#include <iostream>
using namespace std;

namespace bt {
    class Node{
    public:
        Node(int value){ this->value = value; this->left = this->right = NULL; }
        Node():Node(0){};
        Node *left;
        Node *right;
        int value;
    };

    class BinaryTree{
    public:

        void inorderSuccessor(Node *root, Node *target, Node *&next){
            if( !root ) return;

            inorderSuccessor(root->right, target, next);

            if( root->value == target->value ){
                if( next == NULL ) cout << "inorder successor is : NULL";
                else cout << "inorder successor is :"<< next->value;

            }

            next = root;
            inorderSuccessor(root->left, target, next);
        }

        void inorderPredecessor(Node *root, Node *target, Node *&next){
            if( !root ) return;

            inorderSuccessor(root->left, target, next);

            if( root->value == target->value ){
                if( next == NULL ) cout << "inorder predecessor is : NULL";
                else cout << "inorder predecessor is :"<< next->value;

            }

            next = root;
            inorderSuccessor(root->right, target, next);
        }

    };
};

#endif //CPPCOURSE_BINARYTREE_H
