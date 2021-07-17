/*
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
   Created by Lakshmi S. Patel on 25/06/21.
   Copyright (c) 2021, Fight For Education Pvt. Ltd. All rights reserved.
   Please visit us: www.fight4edu.com or www.fight4edu.org
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

#ifndef CPPCOURSE_FREEDOMTRAILLOCK_H
#define CPPCOURSE_FREEDOMTRAILLOCK_H

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;
    int findRotateSteps(string ring, string key) {
        vector<vector<int>> vec( ring.length() , vector<int> (key.length(), -1));
        dp = vec;
        return solve(0,0,ring,key);
    }
    int solve(int i,int j,string ring,string k)
    {
        int n=ring.size();
        int m=k.size();
        if(j==m)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=INT_MAX;
        for(int i1=0;i1<n;i1++)
        {
            if(ring[i1]==k[j])
            {
                int x=abs(i-i1);
                ans=min(ans,min(x,n-x)+solve(i1,j+1,ring,k));
            }
        }
        return dp[i][j]=ans+1;
    }

};
#endif //CPPCOURSE_FREEDOMTRAILLOCK_H
