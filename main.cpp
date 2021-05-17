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
#include "data-struct/graph/Graph.h"
#include "data-struct/graph/DetectCycle.h"
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

int main()
{

    ListNode *a = new ListNode(4);
    a->next = new ListNode(6);

    ListNode *c = new ListNode(14);
    c->next = new ListNode(16);

    ListNode *b = new ListNode(3);
    b->next = new ListNode(10);
    vector<ListNode*> v;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);

    Solution s;
    ListNode *r = s.mergeKLists(v);
    ListNode *t = r;
    while (t){
        cout<< " "<< t->val;
        t = t->next;
    }

    return 0;

}