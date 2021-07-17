/*
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
   Created by Lakshmi S. Patel on 15/07/21.
   Copyright (c) 2021, Fight For Education Pvt. Ltd. All rights reserved.
   Please visit us: www.fight4edu.com or www.fight4edu.org
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

#ifndef CPPCOURSE_MAXCHUNKTOMAKESORTED2_H
#define CPPCOURSE_MAXCHUNKTOMAKESORTED2_H
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& p) {
        int N = p.size();
        int CouNT = 0;
        vector<int> vRN(N+1);
        vRN[N] = INT_MAX;
        for(int i=N-1;i>=0;i--){
            vRN[i] = min(p[i],vRN[i+1]);
        }
        int Lmax = INT_MIN;
        for(int i=0;i<N;i++){
            Lmax = max(Lmax,p[i]);
            if(Lmax <= vRN[i+1]){
                CouNT++;
            }
        }
        return CouNT;
    }
};


#endif //CPPCOURSE_MAXCHUNKTOMAKESORTED2_H
