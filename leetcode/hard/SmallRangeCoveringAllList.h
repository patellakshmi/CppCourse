/*
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
   Created by Lakshmi S. Patel on 03/07/21.
   Copyright (c) 2021, Fight For Education Pvt. Ltd. All rights reserved.
   Please visit us: www.fight4edu.com or www.fight4edu.org
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

#ifndef CPPCOURSE_SMALLRANGECOVERINGALLLIST_H
#define CPPCOURSE_SMALLRANGECOVERINGALLLIST_H
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {

        struct Compare {
            bool operator() (array<int,3>&lhs, array<int,3>&rhs) { return lhs[0] > rhs[0]; }
        };

        //this is min priority queue
        priority_queue<array<int,3>, vector<array<int,3>>, Compare> pq;
        int mx = INT_MIN, lo = -100'000, hi = 100'000;
        for (int i = 0; i < size(nums); ++i) {
            pq.push({nums[i][0], i, 0});
            mx = max(mx, nums[i][0]);
        }

        while (size(pq)) {
            if (mx - pq.top()[0] < hi - lo) {
                lo = pq.top()[0];
                hi = mx;
            }
            auto elem = pq.top(); pq.pop();
            int i = elem[1], j = elem[2];
            if (j+1 == size(nums[i])) break;
            mx = max(mx, nums[i][j+1]);
            pq.push({nums[i][j+1], i, j+1});
        }
        return {lo, hi};
    }
};

#endif //CPPCOURSE_SMALLRANGECOVERINGALLLIST_H
