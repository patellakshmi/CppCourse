//
// Created by Lakshmi S Patel on 22/05/21.
//

#ifndef CPPCOURSE_DIFFSUBSEQGCDS_H
#define CPPCOURSE_DIFFSUBSEQGCDS_H

#include <iostream>
#include <vector>
using namespace std;

//Leetcode hard #1819


class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        //int[] factor = new int[200001];
        vector<int> factor(200001,0);
        for (int i = 0; i < nums.size(); ++i) {
            // Find all factors of nums[i]
            for (int j = 1; j * j <= nums[i]; ++j) {
                if (nums[i] % j == 0) {
                    int factor1 = j;
                    int factor2 = nums[i] / j;

                    // Find gcd of all nums[i] with factor1
                    factor[factor1] = gcd(factor[factor1], nums[i]);

                    // Find gcd of all nums[i] with factor2
                    factor[factor2] = gcd(factor[factor2], nums[i]);
                }

            }
        }
        int ans = 0;
        // Check if all nums with one of factors as i form a GCD of i or not.
        for (int i = 1; i <= 200000; ++i ) if (factor[i] == i) ++ans;
        return ans;
    }

    int gcd(int a, int b) {

        while (b != 0) {
            int t = a;
            a = b;
            b = t % b;
        }
        return a;
    }
};

#endif //CPPCOURSE_DIFFSUBSEQGCDS_H
