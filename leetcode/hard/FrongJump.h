/*
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
   Created by Lakshmi S. Patel on 16/06/21.
   Copyright (c) 2021, Fight For Education Pvt. Ltd. All rights reserved.
   Please visit us: www.fight4edu.com or www.fight4edu.org
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

#ifndef CPPCOURSE_FRONGJUMP_H
#define CPPCOURSE_FRONGJUMP_H
#include <iostream>
#include <map>
#include <set>
using namespace std;
class Solution {
public:

    bool canCross(vector<int>& stones) {
        int size = stones.size();
        int dp[size][size];
        memset(dp,0, sizeof(dp));
        if( stones[0]+1 == stones[1])
            dp[0][1] = 1;
        else return false;

        int k,value;
        for(int i = 0; i < size; i++){
            for(int j = i+1; j < size; j++){
                if( dp[i][j] != 0){ k = j; value = dp[i][j]; }
                for(int t = k+1; t < size; t++){
                    if( stones[k]+value == stones[t]){ dp[k][t] = value; }
                    if( stones[k]+value+1 == stones[t]){ dp[k][t] = value+1; }
                    if( stones[k]+value-1 == stones[t]){ dp[k][t] = value-1; }
                }
            }
        }

        /* for(int i = 0; i < size; i++){
             cout<< endl;
             for(int j = 0; j < size; j++){
                 cout << " "<< dp[i][j];
             }
         }*/

        for(int i = 0; i < size; i++){
            if( dp[i][size-1] != 0) return true;
        }

        return false;
    }

    bool canCrossX(vector<int>& stones) {
        if(stones[1] - stones[0] != 1) return false;
        unordered_map<int, unordered_set<int>> dp;
        for(auto s : stones) dp[s];

        dp[stones[1]].emplace(stones[0]);
        for(int i = 1; i < stones.size(); ++i){
            int stone = stones[i];
            for(auto prev_stone : dp[stone]){
                int64_t k = stone - prev_stone;
                for(int64_t l = k-1; l<=k+1; ++l){
                    if(l < 0) continue;
                    int64_t m = l + stone;
                    if(m > stones.back()) continue;
                    auto it = dp.find(m);
                    if(it == dp.end()) continue;
                    if(it->first == stones.back()) return true;
                    it->second.emplace(stone);
                }
            }
        }
        return false;
    }
};
#endif //CPPCOURSE_FRONGJUMP_H
