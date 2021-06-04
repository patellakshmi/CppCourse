/*
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
   Created by Lakshmi S. Patel on 04/02/21.
   Copyright (c) 2021, Fight For Education Pvt. Ltd. All rights reserved.
   Please visit us: www.fight4edu.com or www.fight4edu.org
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/


#ifndef CPPCOURSE_LLUTIL_H
#define CPPCOURSE_LLUTIL_H
#include <iostream>

using namespace std;

namespace ll {

    class Node {
    public:
        int value;
        Node *next;
        Node *prev;
        Node(int value){ this->value = value; this->next = NULL; }
        Node():Node(0){};
    };

    class LLUtil{

    public:
        Node *makeLinkedList(vector<int> &v);
        Node *newNode(int value){ Node *node = new Node(value  ); return node; }
        Node *DLLToBT(Node **head, int n );
        void printLinkedList(ll::Node *head);

        bool isLoop(Node *head );
        int findLoopLength(Node *head );
        void swap(Node **head_ref, Node *node1, Node *node2 );
        Node *reverse(Node *head);
        Node *reverseInGroup(Node *head, int k);
        Node *pairWiseSwap(Node *head);
        void insertAtStart(Node **head_ref, Node *node);
        void insertAtEnd(Node **head_ref, Node *node);
        Node *getFirstAndRemove(Node **head_ref);
        Node *partition(Node **head_ref);
        void quickSort(Node **head_ref);
        Node* reverseAlt(Node *head_ref, int k );
        Node *merge(Node *a, Node *b);
        void duplicateEachNode(Node *head);
        void seperate(Node *head, Node **b);
        void ajustRandomPointer(Node *head);


    };

};


/* Implementation of function */

/* Let understand pointer first: int *ptr = &b means that ptr is pointer that contains address of b
 * Now if you want to get value at b via pointer we use *ptr for get the value, we want to put something at b *ptr = 5
 * that will work.
 * Similar we need head of link list for accessing the element but sometime we need to modified the head pointer
 * so that in realtime we need to do some operation for that we need a pointer that keep the address of head where head is pointer
 * that keep the address of list list first node so head is pointer and we need to keep the address of this pointer
 * so we require pointer of pointer that is head_ref.
 * Node **head_ref is pointer to pointer.
 * now head_ref is pointer to pointer so if you want to modified the head pointer via head_ref for that we need *head_ref
 * we want to access the value of head that is first node of linked list we can get it by *head_ref;
 * */

ll::Node * ll::LLUtil::DLLToBT(Node **head, int n ){

    if( n<= 0 ) return NULL;

    Node *left = DLLToBT(head, n/2);
    Node *root = *head;

    root->prev = left;
    *head = (*head)->next;

    Node *right = DLLToBT(head, n-n/2-1);
    root->next = right;

    return root;
}

ll::Node * ll::LLUtil::makeLinkedList(vector<int> &v){

    if( v.size() == 0) return NULL;
    Node *head = new Node(v[0]);
    Node *pre = head;
    for(int i = 1; i < v.size(); i++    ){
        Node *curr = new Node(v[i]);
        pre->next = curr;
        pre = curr;
    }

    return head;

}

void ll::LLUtil::printLinkedList(ll::Node *head){
    while (head){
        cout<< " "<< head->value;
        head = head->next;
    }
}

bool ll::LLUtil::isLoop(Node *head ){

    Node *slowPtr = head;
    Node *fastPtr = head;

    while( !slowPtr && !fastPtr && fastPtr->next ){
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
        if( slowPtr == fastPtr ) return true;
    }

    return false;

}

int ll::LLUtil::findLoopLength(Node *head ){

    Node *slowPtr = head;
    Node *fastPtr = head;

    bool isLoop = false;
    while( !slowPtr && !fastPtr && !fastPtr->next ){
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
        if( slowPtr == fastPtr ) {
            isLoop = true;
            break;
        }
    }

    if( isLoop == true  ){
        int count = 0;
        Node *curr = slowPtr->next;
        while( curr != slowPtr ){ count++; curr = curr->next; }
        return ++count;

    }else return -1;

}



void ll::LLUtil::swap(Node **head_ref, Node *node1, Node *node2 ){

    if( *head_ref == NULL ) return;
    if( node1 == node2 ) return;

    Node *prevX = NULL;
    Node *prevY = NULL;
    Node *currX = *head_ref;
    Node *currY = *head_ref;

    while( currX != NULL && currX != node1 ){
        prevX = currX;
        currX = currX->next;
    }

    while( currY != NULL && currY != node2 ){
        prevY = currY;
        currY = currY->next;
    }

    if( currX == NULL || currY == NULL ) return;

    //If Node1 is not head of LL.
    if( prevX != NULL ){
        prevX->next = currY;
    }else{
        *head_ref = currY;
    }


    //If Node2 is not head of LL.
    if( prevY != NULL ){
        prevY->next = currX;
    }else{
        *head_ref = currX;
    }

    Node *temp = currX->next;
    currX->next = currY->next;
    currY->next = temp;

}


ll::Node* ll::LLUtil::reverse(Node *head){

    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;
    while (curr){
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;

    }

    return prev;

}


ll::Node* ll::LLUtil::reverseInGroup(Node *head, int k){

    int count = 1;
    Node *curr = head;
    while(curr != NULL && count < k	){
        curr = curr->next;
        count++;
    }

    if( curr ){
        Node *next = curr->next;
        curr->next = NULL;
        Node *newHead = reverse(head);
        head->next = reverseInGroup(next,k);
        return newHead;
    }
    
    return reverse(head);

}

ll::Node* ll::LLUtil::pairWiseSwap(Node *head){

    if( !head ) return NULL;

    int k = 2;

    Node *curr = head;
    int count = 1;
    while( count< k && curr ){
        count++;
        curr = curr->next;
    }

    if( curr ){
        Node *next = curr->next;
        curr->next = NULL;
        Node *newHead = reverse(head);
        head->next = pairWiseSwap(next);
        return newHead;
    }else{
        return reverse(head);
    }

}

void  ll::LLUtil::insertAtStart(Node **head_ref, Node *node){
    if( *head_ref == NULL){ *head_ref = node; return; }
    node->next = *head_ref;
    *head_ref = node;
}

void  ll::LLUtil::insertAtEnd(Node **head_ref, Node *node){
    if( *head_ref == NULL){ *head_ref = node; return; }

    Node *end = *head_ref;
    while (end->next != NULL){
        end = end->next;
    }
    end->next = node;
}

ll::Node* ll::LLUtil::getFirstAndRemove(Node **head_ref){
    if( *head_ref == NULL){ return  NULL; }
    Node *node = *head_ref;
    *head_ref = node->next;
    node->next = NULL;
    return node;
}

/* Partition is algorithm, that partition LLUtil by pivot element.
 * First we need to get the pivot element that is here last element.
 * Create the two list that are lessList, greatList, one contains only lesser element than pivot
 * another contains the greater element than pivot.
 * Now we need to join the these two list with pivot as lessList than pivot than greatList.
 *  */
ll::Node* ll::LLUtil::partition(Node **head_ref) {

    Node *pivot = *head_ref;
    Node *prevPivot = NULL;
    while (pivot->next) {
        prevPivot = pivot;
        pivot = pivot->next;
    }

    prevPivot->next = NULL;

    Node *lessHead = NULL;
    Node *greaterHead = NULL;

    while (*head_ref ) {
        Node *temp = getFirstAndRemove(head_ref);
        if (temp->value > pivot->value) {
            insertAtStart(&greaterHead, temp);
        } else {
            insertAtStart(&lessHead, temp);
        }

    }

    greaterHead = reverse(greaterHead);
    lessHead = reverse(lessHead);

    pivot->next = greaterHead;

    Node *lessEnd = lessHead;
    while (lessEnd->next) {
        lessEnd = lessEnd->next;
    }

    lessEnd->next = pivot;

    *head_ref = lessHead;
    return pivot;

}

/* QuickSort : We need to get pivot element, with help of pivot element we break original list greatList and lessList
 * we need to recur the quickSort for lessList, greatList after that combine the list.
 * */
void ll::LLUtil::quickSort(Node **head_ref){

    //Base case
    if( *head_ref == NULL || (*head_ref)->next == NULL) return;

    //General case
    Node *pivot = partition(head_ref);
    Node *prev = *head_ref;
    while (prev->next != pivot){ prev = prev->next; }
    prev->next = NULL;

    Node *lessHead = *head_ref;
    Node *greatHead = pivot->next;
    pivot->next = NULL;
    prev->next = NULL;

    quickSort(&lessHead);
    quickSort(&greatHead);

    //Need to combine both
    Node *lessEndNode = lessHead;
    while (lessEndNode->next){ lessEndNode = lessEndNode->next; }

    lessEndNode->next = pivot;
    pivot->next = greatHead;

    *head_ref = lessHead;

}

ll::Node* ll::LLUtil::reverseAlt(Node *head, int k ){

    if( (head) == NULL ) return NULL;

    int count = 1;
    Node *curr = head;
    while( curr != NULL & count < k ){
        curr = curr->next;
        count++;
    }

    if( curr == NULL ){
        return reverse(head);
    }else{

        Node *nextHead = curr->next;
        curr->next = NULL;
        Node *newHead = reverse(head);

        Node *temp = nextHead;
        int tempCount =1;
        while( temp != NULL & tempCount < k ){
            temp = temp->next;
            tempCount++;
        }

        if( temp == NULL ){
            (head)->next = nextHead;
        }else{
            (head)->next = nextHead;
            temp->next = reverseAlt((temp->next), k);
        }

        return newHead;
    }

}


ll::Node * ll::LLUtil::merge(Node *a, Node *b){

    if( a == NULL ) return b;
    if( b == NULL ) return a;


    if( a->value < b->value ){
        a->next = merge(a->next, b);
        return a;
    }else if( a->value > b->value){
        b->next = merge(a, b->next);
        return b;
    }


    Node *aCurr = a;
    Node *bCurr = b;
    Node *aNext = a->next;
    Node *bNext = b->next;
    aCurr->next = bCurr;
    bCurr->next = merge(aNext, bNext);
    return aCurr;

}


void ll::LLUtil::duplicateEachNode(Node *head){

    if( !head ) return;
    Node *curr = head;
    Node *next = NULL;

    while(curr){
        next = curr->next;
        Node *node = new Node(curr->value);
        curr->next = node;
        node->next = next;
        curr = next;

    }

}

void ll::LLUtil::ajustRandomPointer(Node *head){
    if( !head ) return;

    Node *curr = head;
    while(curr){

        //Please make random pointer
        /*
        Node *nextCurr = curr->next;
        Node *ramdomPtr = curr->random;
        Node *nextRandomNode = randomPtr->next;
        nextCurr->random = nextRandomNode;
        curr = curr->next->next;
         */
    }


}


void ll::LLUtil::seperate(Node *head, Node **b){

    if( !head ) return;

    *b = head->next;
    Node *curr = head;
    Node *next = head->next;
    while(curr){
        Node *nextTemp = NULL;
        Node *currTemp = curr->next->next;
        if( currTemp )
            nextTemp = next->next->next;
        curr->next = curr->next->next;
        if( currTemp)
            next->next = next->next->next;
        curr = currTemp;
        if( currTemp)
            next = nextTemp;
    }

}





#endif //CPPCOURSE_LLUTIL_H
