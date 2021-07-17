/*
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
   Created by Lakshmi S. Patel on 25/06/21.
   Copyright (c) 2021, Fight For Education Pvt. Ltd. All rights reserved.
   Please visit us: www.fight4edu.com or www.fight4edu.org
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

#ifndef CPPCOURSE_MAXSUMRECT_H
#define CPPCOURSE_MAXSUMRECT_H

#include <iostream>
#include <vector>
using namespace std;

/*

Given an m x n matrix matrix and an integer k, return the max sum of a rectangle in the matrix such that its sum is no larger than k.
It is guaranteed that there will be a rectangle with a sum no larger than k.

 */


class Solution {
public:
    int max(int a, int b){ if( a > b) return a; return b;}

    int getMax(vector<int> &dp, int k){
        int globalMax = INT_MIN;
        int localMax = 0;
        vector<int> preDP(dp.size(), 0);
        for(int i = 0; i < dp.size(); i++){
            preDP[i] = dp[i];
        }

        for(int i = 1; i < dp.size(); i++){
            preDP[i] = preDP[i]+preDP[i-1];
        }


        for(int i = 0; i < dp.size(); i++){
            localMax = 0;
            for(int j = i; j < dp.size(); j++){
                if( i == 0 ){
                    localMax = preDP[j];
                }else{
                    localMax = preDP[j]-preDP[i-1];
                }
                if( localMax <= k){
                    globalMax = max(globalMax, localMax);
                }
            }
        }

        return globalMax;
    }

    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> dp(m, 0);

        int res = INT_MIN;
        int temp = 0;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                for(int k = 0; k < m; k++){
                    temp = 0;
                    for(int t = i; t <= j; t++){
                        temp += matrix[k][t];
                    }
                    dp[k] = temp;
                }

                int localMx = getMax(dp, k);
                if( localMx <= k)
                    res = max(res, localMx);
            }
        }

        return res;
    }
};

#endif //CPPCOURSE_MAXSUMRECT_H
