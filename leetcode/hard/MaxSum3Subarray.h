/*
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
   Created by Lakshmi S. Patel on 10/07/21.
   Copyright (c) 2021, Fight For Education Pvt. Ltd. All rights reserved.
   Please visit us: www.fight4edu.com or www.fight4edu.org
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

#ifndef CPPCOURSE_MAXSUM3SUBARRAY_H
#define CPPCOURSE_MAXSUM3SUBARRAY_H

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int> sum(nums.size()-k+1, 0);
        int temp = 0;
        int i = 0;
        while ( i < nums.size() ){
            if( i < k ) temp += nums[i];
            else{
                sum[i-k] = temp;
                temp = temp-nums[i-k]+nums[i];
            }
            i++;
        }
        sum[i-k] = temp;

        vector<int> left(sum.size(), 0);
        int best = 0;
        for(int i = 0; i < sum.size(); i++){
            if( sum[i] > sum[best] ) best = i;
            left[i] = best;
        }

        vector<int> right(sum.size(), 0);
        best = sum.size()-1;
        for(int i = sum.size()-1; i >= 0; i--){
            if( sum[i] > sum[best] ) best = i;
            right[i] = best;
        }

        vector<int> ans(3,-1);
        for(int j = k; j < sum.size()-k; j++){
            int i = left[j - k], l = right[j + k];
            if (ans[0] == -1 || sum[i] + sum[j] + sum[l] > sum[ans[0]] + sum[ans[1]] + sum[ans[2]]) {
                ans[0] = i;
                ans[1] = j;
                ans[2] = l;
            }
        }

        return ans;
    }
};

#endif //CPPCOURSE_MAXSUM3SUBARRAY_H
