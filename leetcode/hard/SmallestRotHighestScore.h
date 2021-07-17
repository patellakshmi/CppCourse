/*
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
   Created by Lakshmi S. Patel on 14/07/21.
   Copyright (c) 2021, Fight For Education Pvt. Ltd. All rights reserved.
   Please visit us: www.fight4edu.com or www.fight4edu.org
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

#ifndef CPPCOURSE_SMALLESTROTHIGHESTSCORE_H
#define CPPCOURSE_SMALLESTROTHIGHESTSCORE_H
#include <iostream>
#include <vector>
using namespace std;

/*
Consider the element A[i]:

If A[i] <= i, then to get 1 point for this element, K has to be in either [0,i-A[i]] or [i+1, N].
If A[i] > i, then to get 1 point for this element, K has to be in [i+1, N-A[i]+i]
The problem is then converted to the interval accumulation problem: we scan each element in A and accumulate their effective intervals. For each interval [a,b], one score is added to all numbers between a and b. At the end, we return the K with the maximum score. The classical O(N) solution for this interval accumulation problem is used.

*/

class Solution {
public:
    int bestRotation(vector<int>& A) {
        const int N = A.size();
        // vector to accumulate intervals
        // For a position k, the accumulated score is the sum of tmp[0] + ... + tmp[k]
        vector<int> tmp(N+1, 0);

        for (int i(0); i < N; ++i) {
            if (A[i] <= i) {
                // if A[i] <= i, K in [0,i-A[i]] or [i+1, N-1] to get 1 point
                tmp[0] += 1;
                tmp[i-A[i]+1] -= 1;
                tmp[i+1] += 1;
                tmp[N] -= 1;
            }
            else {
                // if A[i] > i, K in [i+1, N-A[i]+i] to get 1 point
                tmp[i+1] += 1;
                tmp[N-A[i]+i+1] -= 1;
            }
        }

        // count to get maximum
        int maxc = INT_MIN;
        int maxK = -1;
        int cur = 0;
        for (int i(0); i < N; ++i) {
            cur += tmp[i];
            if (cur > maxc) {
                maxc = cur;
                maxK = i;
            }
        }
        return maxK;
    }
};

#endif //CPPCOURSE_SMALLESTROTHIGHESTSCORE_H
