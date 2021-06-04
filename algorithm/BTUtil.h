/*
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
   Created by Lakshmi S. Patel on 03/02/21.
   Copyright (c) 2021, Fight For Education Pvt. Ltd. All rights reserved.
   Please visit us: www.fight4edu.com or www.fight4edu.org
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

#ifndef CPPCOURSE_BTUTIL_H
#define CPPCOURSE_BTUTIL_H

#include <iostream>
#include <stack>
#include <queue>
#include <map>
using namespace std;

namespace bt {

    class Node{
    public:
        Node(int value){ this->value = value; this->left = this->right = NULL; }
        Node():Node(0){};
        Node *left;
        Node *right;
        int value;
        int height;
    };

    class BTUtil{
    public:

        void inorderSuccessor(Node *root, Node *target, Node *&next);
        void inorderPredecessor(Node *root, Node *target, Node *&next);

        void inorderTraversal(Node *root);
        void inorderMorrisTraversal(Node *root);

        void preorderMorrisTraversal(Node *root);
        void preorderTraversal(Node *root);
        void postorderTraversal(Node *root);
        void postorderTraversalWithOneStack(Node *root);

        int getHeight(Node *root);

        int BTToChildSumBT(Node *root);
        Node* convertToBT(vector<int> &v);
        void printBT(Node *root);
        void printBottomView(Node *root);
        int diameter(Node *root, int *res);
        pair<int,bt::Node*> diameterOfBTWithNodes(Node *root, int *res, Node **node1, Node **node2);

    };

    class AVLTree{

    public:
        Node *leftRotate(Node *y);
        Node *rightRotate(Node *y);
        int getHeight(Node *root);
        Node* insertKey(Node *root, int key);
        int getBalance(Node *root);

    };

};






void bt::BTUtil::inorderPredecessor(Node *root, Node *target, Node *&next){
    if( !root ) return;

    inorderSuccessor(root->left, target, next);

    if( root->value == target->value ){
        if( next == NULL ) cout << "inorder predecessor is : NULL";
        else cout << "inorder predecessor is :"<< next->value;
        return;
    }

    next = root;
    inorderSuccessor(root->right, target, next);
}


void bt::BTUtil::inorderSuccessor(Node *root, Node *target, Node *&next){
    if( !root ) return;

    inorderSuccessor(root->right, target, next);

    if( root->value == target->value ){
        if( next == NULL ) cout << "inorder successor is : NULL";
        else cout << "inorder successor is :"<< next->value;
        return;

    }

    next = root;
    inorderSuccessor(root->left, target, next);
}

// iterative inorderTraversal using stack
void bt::BTUtil:: inorderTraversal(Node *root){

    if( !root ) return;
    stack<Node *> s;
    Node *curr = root;

    while ( !curr || !s.empty()  ){

        while ( !curr ){
            s.push(curr);
            curr = curr->left;
        }

        Node *node = s.top();
        s.pop();
        cout<< " "<< node->value;

        curr = node->right;
    }

}


// Iterative algorithms for preorder traversal.
void bt::BTUtil::preorderTraversal(Node *root){

    if( !root ) return;

    stack<Node *> s;
    s.push(root);

    while (!s.empty()){

        Node *node = s.top();
        cout<< " "<< node->value;

        s.pop();
        if( node->right != NULL)
            s.push(node->right);

        if( node->left != NULL)
            s.push(node->left);

    }
}

// Iterative algorithms for postorder traversal.
void bt::BTUtil::postorderTraversal(Node *root){

    if( root == NULL ) return;

    stack<Node *> s1, s2;
    s1.push(root);
    while (!s1.empty()){

        Node *curr = s1.top();
        s1.pop();
        s2.push(curr);
        if( curr->left ) s1.push(curr->left);
        if( curr->right ) s1.push(curr->right);

    }

    while (!s2.empty()){
        cout<< " "<< s2.top();
        s2.pop();
    }

}

// iterative inorderTraversal using morris traversal
void bt::BTUtil:: inorderMorrisTraversal(Node *root){

    if( !root ) return;
    Node *current = root;

    while (current){

        if( current->left == NULL ){
            cout<< " "<< current->value;
            current = current->right;
        }else{
            Node *pre = current->left;
            while (pre->right != NULL || current->right != current ){
                pre = pre->right;
            }

            if( pre->right == NULL ){
                pre->right = current;
                current = current->left;
            }else{
                pre->right = NULL;
                cout<< " "<< current->value;
                current = current->right;
            }
        }
    }
}


void bt::BTUtil::preorderMorrisTraversal(Node *root) {

    if( !root ){ return; }

    Node *current = root;
    Node *prev;

    while (current){

        if( current->left == NULL){
            cout<< " "<< current->value;
            current = current->right;
        }else {

            prev = current->left;
            while (prev->right && prev->right != current) {
                prev = prev->right;
            }

            if (prev->right == NULL) {
                cout<< " "<< current->value;
                prev->right = current;
                current = current->left;

            } else {

                current->right = NULL;
                current = current->right;

            }
        }
    }
}


void bt::BTUtil::postorderTraversalWithOneStack(Node *root){

    if( !root ) return;

    Node *current = root;
    stack<Node *> s;

    do{

        while ( current ){
            if( current->right) s.push(current->right);
            s.push(current);
            current = current->left;
        }

        current = s.top();
        s.pop();

        if( current->right == s.top() ){
            s.pop();
            s.push(current);
            current = current->right;
        }else{
            cout<< " "<< current->value;
            current = NULL;
        }

    } while (!s.empty());


}



bt::Node* bt::AVLTree::rightRotate(Node *y){

    Node *x = y->left;
    Node *t2 = x->right;

    x->right = y;
    y->left = t2;

    y->height = getHeight(y);
    x->height = getHeight(x);

    return x;
}


bt::Node* bt::AVLTree::leftRotate(Node *y){

    Node *x = y->right;
    Node *t1 = x->left;

    x->left = y;
    y->right = t1;

    y->height = getHeight(y);
    x->height = getHeight(x);

    return x;
}

int bt::BTUtil::getHeight(Node *root){
    if( root == NULL) return 0;
    int l = getHeight(root->left);
    int r = getHeight(root->right);
    return l > r ? l+1: r+1;
}

int bt::AVLTree::getHeight(Node *root){
    if( root == NULL) return 0;
    int l = getHeight(root->left);
    int r = getHeight(root->right);
    return l > r ? l+1: r+1;
}


int bt::AVLTree::getBalance(Node *root){

    if( root == NULL) return 0;

    return ( getHeight(root->left)-getHeight(root->right));
}


bt::Node* bt::AVLTree::insertKey(Node *root, int key){

    if( root == NULL){
        Node *node;

        node->height = 0;
        node->left = NULL;
        node->left = NULL;

        return node;

    }

    if( root->value > key){
        root->left = insertKey(root->left, key);
    }else if( root->value < key){
        root->right = insertKey(root->right, key);
    }else{
        return root;
    }

    root->height = 1+max(getHeight(root->left), getHeight(root->right));
    int balance = getBalance(root);

    //Left Left case
    if( balance == 1 && key < root->left->value ){
        return rightRotate(root);
    }

    //Right Right case
    if( balance == -1 &&  root->left->value < key ){
        return leftRotate(root);
    }

    //Left right case
    if( balance == 1 && key > root->left->value ){
        root->left = rightRotate(root->left);
        return leftRotate(root);

    }

    //Right left case
    if( balance == -1 &&  root->right->value > key ){
        root->right = leftRotate(root->left);
        return rightRotate(root);

    }

    return root;

}


int bt::BTUtil::BTToChildSumBT(Node *root){

    if( !root ) return 0;
    if( root->right == NULL && root->left == NULL ) return root->value;

    int leftSum = 0;
    int rightSum = 0;
    if( root->left ) leftSum = BTToChildSumBT(root->left);
    if( root->right ) leftSum = BTToChildSumBT(root->right);

    root->value = root->value + leftSum + rightSum;
    return root->value;


}

bt::Node * bt::BTUtil::convertToBT(vector<int> &v){

    cout<< "size of vector: "<< v.size();
    cout<<endl;
    queue<Node*> q;
    static int counter = 0;
    Node *root = new Node(v[counter]);
    q.push(root);

    while(!q.empty()){
        Node *front = q.front();
        q.pop();

        if( ++counter == v.size() ) break;
        Node *left = new Node(v[counter]);
        front->left = left;
        q.push(left);

        if( ++counter == v.size() ) break;
        Node *right = new Node(v[counter]);
        front->right = right;
        q.push(right);

    }

    return root;
}

void bt::BTUtil::printBT(Node *root){
    if( !root ) return;

    cout<< " "<< root->value;
    printBT(root->left);
    printBT(root->right);
}

void bt::BTUtil::printBottomView(Node *root){

    if(!root ) return;

    map<int,Node *> m;
    queue<pair<int, Node*>> q;
    q.push(make_pair(0, root));

    while(!q.empty()){
        pair<int, Node *> mypair = q.front();
        q.pop();

        m[mypair.first] = mypair.second;

        if( mypair.second->left ) {
            int hashValue = mypair.first -1;
            q.push(make_pair(hashValue,  mypair.second->left ));
        }

        if( mypair.second->right ) {
            int hashValue = mypair.first +1;
            q.push(make_pair(hashValue,  mypair.second->right ));
        }
    }

    map<int, Node*>::iterator it;
    for(it = m.begin(); it != m.end(); it++){
        cout<< "--" << ((it)->second)->value;
    }
}


int bt::BTUtil::diameter(Node *root, int *res){

    if( !root ) return 0;

    int leftHeight = diameter(root->left, res);
    int rightHeight = diameter(root->right, res);

    if( leftHeight+ rightHeight +1  > *res){
        *res = leftHeight+ rightHeight + 1;
    }

    if( leftHeight > rightHeight ){
        return leftHeight + 1;
    }else{
        return rightHeight +1;
    }

}


pair<int,bt::Node*> bt::BTUtil::diameterOfBTWithNodes(Node *root, int *res, Node **node1, Node **node2){

        if( !root ) return make_pair(0,root);

        pair<int, Node*> left = diameterOfBTWithNodes(root->left, res, node1, node2);
        pair<int, Node*> right =diameterOfBTWithNodes(root->right, res, node1, node2);

        if( left.first + right.first + 1 > *res){
            *node1 = left.second;
            *node2 = right.second;
            *res = left.first+ right.first + 1;
        }

        if( left.first == 0 && right.first == 0 ){
            return make_pair(1,root);
        }

        if( left.first > right.first ){
            return make_pair(left.first + 1, left.second);
        }else{
            return make_pair(right.first + 1, right.second);
        }

}


#endif //CPPCOURSE_BTUTIL_H
