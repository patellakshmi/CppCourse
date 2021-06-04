//
// Created by Lakshmi S Patel on 19/05/21.
//

#ifndef CPPCOURSE_WATERTRAP_H
#define CPPCOURSE_WATERTRAP_H

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <string>
#include <set>
#include <unordered_set>
#include <thread>
#include <list>
#include <stack>

using namespace std;

class SolutionBest {
public:
    int trap(vector<int>& A) {
        if(A.size() == 0) return 0;
        vector<int> maxLeft(A.size(), 0);
        vector<int> maxRight(A.size(), 0);
        maxLeft[0] = A[0];
        for(int i=1; i<A.size(); i++) {
            maxLeft[i] = max(maxLeft[i-1], A[i]);
        }
        maxRight[A.size()-1] = A[A.size()-1];
        for(int i=A.size()-2; i>=0; i--)
            maxRight[i] = max(maxRight[i+1], A[i]);
        int ans = 0;
        for(int i=0; i<A.size(); i++) {
            ans += min(maxLeft[i], maxRight[i]) - A[i];
        }
        return ans;
    }
};

class Solution {
public:

    void nearByGreaterHeightIndex(vector<int> &height, map<int,int> &res, stack<int>&s, int i){
        if( s.empty()) {
            res[i] =-1;
            s.push(i);
        }else{
            if( height[s.top()] > height[i] ){
                res[i] = s.top();
                s.push(i);
            }else{
                while (!s.empty() && height[s.top()] <= height[i]){
                    s.pop();
                }

                if( s.empty() ) {
                    res[i] =-1;
                    s.push(i);
                }else{
                    res[i] = s.top();
                    s.push(i);
                }

            }
        }
    }

    map<int,int> rightMax(vector<int>& height){
        map<int,int> res;
        stack<int> s;
        res[height.size()-1] = -1;
        for(int i = height.size()-1; i >= 0; i--){
            nearByGreaterHeightIndex(height, res, s, i);
        }

        return res;
    }

    map<int,int> leftMax(vector<int>& height){
        map<int,int> res;
        stack<int> s;
        res[0] = -1;
        for(int i = 0; i < height.size(); i++){
            nearByGreaterHeightIndex(height, res, s, i);
        }

        return res;
    }

    int min(int a, int b){
        if( a < b)return a;
        return b;
    }

    int trap(vector<int>& height) {
        map<int,int> left = leftMax(height);
        map<int,int> right = rightMax(height);
        int totalWater = 0;

        unordered_set<string> s;
        for(int i = 0; i < height.size(); i++){

            string key = to_string(height[i]) +"#"+to_string(left[i])+"#"+to_string(right[i]);
            if( s.find(key) != s.end()){
                continue;;
            }

            if( left[i] != -1 && right[i] != -1){
                totalWater += ( right[i]-left[i]-1 )*( min( height[right[i]], height[left[i]])-height[i] );
                string key = to_string(height[i]) +"#"+to_string(left[i])+"#"+to_string(right[i]);
                s.insert(key);
            }

        }

        return totalWater;
    }
};

#endif //CPPCOURSE_WATERTRAP_H
