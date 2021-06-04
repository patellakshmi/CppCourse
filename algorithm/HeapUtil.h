/*
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
   Created by Lakshmi S. Patel on 04/02/21.
   Copyright (c) 2021, Fight For Education Pvt. Ltd. All rights reserved.
   Please visit us: www.fight4edu.com or www.fight4edu.org
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

#ifndef CPPCOURSE_HEAPUTIL_H
#define CPPCOURSE_HEAPUTIL_H

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

namespace hu{

    class StreamProcessing{
        int minQSize;
        int maxQSize;
        priority_queue<int, vector<int>, greater<int>> minQ;
        priority_queue<int, vector<int>, less<int>> maxQ;

    public:
        StreamProcessing(int minQSize, int maxQSize){ this->minQSize = minQSize; this->maxQSize = maxQSize;}
        StreamProcessing():StreamProcessing(0,0){};
        int kthLargest(int x);
        int kthSmallest(int x);
        double median(int x);
    };

}


int hu::StreamProcessing::kthLargest(int x) {

    if( minQ.size() < minQSize){
        minQ.push(x);
        return -1;
    }else{
        if( x > minQ.top()){
            minQ.pop();
            minQ.push(x);
        }

        return minQ.top();
    }

}

int hu::StreamProcessing::kthSmallest(int x){

    if( maxQ.size() < minQSize){
        maxQ.push(x);
        return -1;
    }else{
        if( x < maxQ.top()){
            maxQ.pop();
            maxQ.push(x);
        }

        return maxQ.top();
    }

}

double hu::StreamProcessing::median(int x){

    if( maxQ.size() == 0){ maxQ.push(x); return maxQ.top(); }

    if( minQ.size() == 0 ){
        if( x >= maxQ.top() ){
            minQ.push(x);
        }else{
            int top = maxQ.top(); maxQ.pop();
            minQ.push(top);
            maxQ.push(x);
        }
    } else if( x < maxQ.top()){
        if( maxQ.size() == minQ.size()){
            maxQ.push(x);
        }else if(maxQ.size() < minQ.size()){
            maxQ.push(x);
        }else{
            int top = maxQ.top(); maxQ.pop();
            minQ.push(top);
            maxQ.push(x);
        }
    }else if( x > minQ.top()){
        if( maxQ.size() == minQ.size()){
            minQ.push(x);
        }else if( maxQ.size() > minQ.size()){
            minQ.push(x);
        }else{
            int top = minQ.top(); minQ.pop();
            maxQ.push(top);
            minQ.push(x);
        }
    }else{
        if( maxQ.size() == minQ.size()){
            maxQ.push(x);
        }else if(maxQ.size() < minQ.size()){
            maxQ.push(x);
        }else{
            int top = maxQ.top(); maxQ.pop();
            minQ.push(top);
            maxQ.push(x);
        }
    }

    if( maxQ.size() == minQ.size()){ double mean = (double )( maxQ.top()+ minQ.top())/2; return mean; }
    else if( maxQ.size() >= minQ.size()){ return maxQ.top(); }
    else { return minQ.top(); }

}


#endif //CPPCOURSE_HEAPUTIL_H
