/*
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
   Created by Lakshmi S. Patel on 06/07/21.
   Copyright (c) 2021, Fight For Education Pvt. Ltd. All rights reserved.
   Please visit us: www.fight4edu.com or www.fight4edu.org
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

#ifndef CPPCOURSE_STUDENTATTENDENCERECORD_H
#define CPPCOURSE_STUDENTATTENDENCERECORD_H

#include <iostream>
#include <vector>
using namespace std;

/*
 * https://massivealgorithms.blogspot.com/2017/04/leetcode-552-student-attendance-record.html
 */

class Solution {
public:
    int checkRecord(int n) {
        int m = 1000000007;
        int A[n];
        int P[n];
        int L[n];

        if(n == 1) return 3;
        if(n == 0 ) return 0;
        if( n == 2 ) return 8;

        P[0] = 1;
        L[0] = 1;
        L[1] = 3;
        A[0] = 1;
        A[1] = 2;
        A[2] = 4;



        for(int i = 1; i < n; i++)
        {
            A[i - 1] %= m;
            P[i - 1] %= m;
            L[i - 1] %= m;

            P[i] = ((A[i - 1] + P[i - 1]) % m + L[i - 1]) % m;

            if(i > 1) L[i] = ((A[i - 1] + P[i - 1]) % m + (A[i - 2] + P[i - 2]) % m) % m;

            if(i > 2) A[i] = ((A[i - 1] + A[i - 2]) % m + A[i - 3]) % m;
        }

        return ((A[n - 1] % m + P[n - 1] % m) % m + L[n - 1] % m) % m;
    }
};


#endif //CPPCOURSE_STUDENTATTENDENCERECORD_H
