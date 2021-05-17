//
// Created by Lakshmi S Patel on 18/05/21.
//

#ifndef CPPCOURSE_MERGEKSORTEDLISTS_H
#define CPPCOURSE_MERGEKSORTEDLISTS_H

#include <iostream>
#include "algorithm/Util.h"
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <string>
#include <set>
#include <unordered_set>
#include <thread>
#include <list>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {

    ListNode *reverseUtil(ListNode *r){

        ListNode *pre = nullptr;
        ListNode *curr = r;
        ListNode *next = nullptr;

        while (curr){
            next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }

        return pre;
    }

    ListNode *merge(ListNode *a, ListNode *b){
        ListNode *r = nullptr;
        ListNode *l = nullptr;

        if( a == nullptr) return b;
        if( b == nullptr) return a;

        while( a != nullptr && b != nullptr){
            if( a->val < b->val){
                if( r != nullptr){
                    ListNode *temp = new ListNode(a->val);
                    l->next = temp;
                    l = temp;
                    a = a->next;
                }else{
                    ListNode *temp = new ListNode(a->val);
                    a = a->next;
                    r = temp;
                    l = temp;
                }
            }else{
                if( r != nullptr){
                    ListNode *temp = new ListNode(b->val);
                    l->next = temp;
                    l = temp;
                    b = b->next;
                }else{
                    ListNode *temp = new ListNode(b->val);
                    b = b->next;
                    r = temp;
                    l = temp;
                }
            }
        }

        ListNode *t = r;
        while (t->next){
            t = t->next;
        }

        if( a == nullptr){
            t->next = b;
        }else{
            t->next = a;
        }

        return r;

    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *r = nullptr;
        ListNode *a = nullptr;
        for(ListNode *b: lists){
            a = r;
            r = merge(b, a);
        }

        return r;
    }
};



#endif //CPPCOURSE_MERGEKSORTEDLISTS_H
