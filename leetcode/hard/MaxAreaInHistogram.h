//
// Created by Lakshmi S Patel on 20/05/21.
//

#ifndef CPPCOURSE_MAXAREAINHISTOGRAM_H
#define CPPCOURSE_MAXAREAINHISTOGRAM_H

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

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        stack<int> s;
        int area;
        int maxArea = INT_MIN;

        int i = 0;

        while(i < heights.size()){

            if( s.empty() || heights[s.top()] <= heights[i] ){
                s.push(i++);
            }else{

                int top = s.top(); s.pop();
                area = heights[top] * ( s.empty() ? i: i-s.top()-1 );
                if( maxArea < area){
                    maxArea = area;
                }

            }
        }


        while( !s.empty() ){
            int top = s.top(); s.pop();
            area = heights[top] * ( s.empty() ? i: i-s.top()-1 );
            if( maxArea < area){
                maxArea = area;
            }
        }

        return maxArea;
    }
};

#endif //CPPCOURSE_MAXAREAINHISTOGRAM_H
