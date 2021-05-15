//
// Created by Lakshmi S Patel on 06/02/21.
//

#ifndef CPPCOURSE_MULTILABELLIST_H
#define CPPCOURSE_MULTILABELLIST_H

namespace mll{

    class Node{
    public:
        int value;
        Node *next;
        Node *down;
        Node(int value){ this->value = value; this->next = NULL; this->down = NULL; }
        Node():Node(0){};
    };

    class MultiLabeledList{
        Node  *flattenMultiLabeledLinkedList(Node *root);
    };
}


mll::Node  * mll::MultiLabeledList::flattenMultiLabeledLinkedList(Node *root){

    /*
    1->2->3->4->5->7->8->9->10
    |           |
    5->4->9     |
    |           10->45->90
    7
     */

    /*
     1->2->3->4->5->7->8->9->10->5->4->9->10->45->90->7
     */

    if( !root ) return root;


    Node *curr = root;
    Node *tail = root;

    while (tail->next){
        tail = tail->next;
    }

    while (curr){

        if(curr->down) {
            tail->next = curr->down;
            Node *temp = curr->down;
            while (temp->next){
                temp = temp->next;
            }

            tail = temp;
        }

        curr = curr->next;
    }

    return root;

}


#endif //CPPCOURSE_MULTILABELLIST_H
