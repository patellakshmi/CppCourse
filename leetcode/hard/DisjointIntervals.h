/*
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
   Created by Lakshmi S. Patel on 22/06/21.
   Copyright (c) 2021, Fight For Education Pvt. Ltd. All rights reserved.
   Please visit us: www.fight4edu.com or www.fight4edu.org
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

#ifndef CPPCOURSE_DISJOINTINTERVALS_H
#define CPPCOURSE_DISJOINTINTERVALS_H

#include <set>
#include <unordered_set>
#include <thread>
#include <list>
#include <stack>
using namespace std;

class SummaryRangesXX {
public:
    /** Initialize your data structure here. */
    set<int>record;
    vector<int>Father;
    SummaryRanges() {
        Father.resize(10001);
        for(int i=0;i<10001;i++)Father[i]=-1;
    }
    int FindFather(int x)
    {
        if(Father[x]==x)return x;
        return Father[x]=FindFather(Father[x]);
    }
    void addNum(int val) {
        if(Father[val]!=-1)return;
        int left=-1,right=-1;
        if(val-1>=0)left=Father[val-1];
        if(val+1<10001)right=Father[val+1];
        if(left!=-1&&right!=-1)
        {
            // cout << val << " " << left << " " << right << endl;
            record.erase(val-1);
            FindFather(val-1);
            Father[val]=Father[val-1];
            Father[val+1]=Father[val-1];
        }else if(left!=-1)
        {
            record.erase(val-1);
            record.insert(val);
            FindFather(val-1);
            Father[val]=Father[val-1];
        }else if(right!=-1)
        {
            Father[val]=val;
            FindFather(val+1);
            Father[val+1]=val;
        }else
        {
            Father[val]=val;
            record.insert(val);
        }
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>>res;
        for(auto &x:record)
        {
            FindFather(x);
            res.push_back({Father[x],x});
        }
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */

class SummaryRanges {
    set<set<int>> allSet;

    bool isPresent(int value){
        for(set<int> s: allSet){
            if( s.find(value) != s.end()) return true;
        }

        return false;
    }

    void setUnion(){
        set<set<int>>::iterator curr = allSet.begin();
        set<set<int>>::iterator prev = curr;
        curr++;
        for( ; curr != allSet.end(); ){
            set<int>::iterator  fIt, sIt;
            fIt = (*prev).end();
            fIt--;
            sIt = (*curr).begin();
            if( (*fIt + 1) == *sIt){
                set<int> &prevSet = const_cast<set<int> &> (*prev);
                for(auto x: *curr){
                    prevSet.insert(x);
                }
                curr = allSet.erase(curr);
            }else{
                prev = curr;
                curr++;
            }

        }
    }

public:
    /** Initialize your data structure here. */
    SummaryRanges() {

    }

    void addNum(int val) {
        if( !isPresent(val) ){
            set<int> s;
            s.insert(val);
            allSet.insert(s);
            setUnion();
        }
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        for(set<int> s: allSet){
            vector<int> v;
            set<int>::iterator it;
            it = s.begin();
            v.push_back(*it);
            it = s.end();
            it--;
            v.push_back(*it);
            res.push_back(v);
        }

        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */

#endif //CPPCOURSE_DISJOINTINTERVALS_H
