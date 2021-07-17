/*
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
   Created by Lakshmi S. Patel on 25/06/21.
   Copyright (c) 2021, Fight For Education Pvt. Ltd. All rights reserved.
   Please visit us: www.fight4edu.com or www.fight4edu.org
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

#ifndef CPPCOURSE_ENVELOPSFIXED_H
#define CPPCOURSE_ENVELOPSFIXED_H

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int max(int a, int b){ if( a > b) return a; return b; }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        vector<int> dp(envelopes.size(), 1);
        sort(envelopes.begin(), envelopes.end());
        for(int i = 1; i < envelopes.size(); i++){
            for(int j = 0; j < i; j++){
                if( envelopes[j][0] < envelopes[i][0] &&
                    envelopes[j][1] < envelopes[i][1] ){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }

        int res = INT_MIN;
        for(int i = 0; i < envelopes.size(); i++){
            res = max(res, dp[i]);
        }

        return res;

    }
};

#endif //CPPCOURSE_ENVELOPSFIXED_H
