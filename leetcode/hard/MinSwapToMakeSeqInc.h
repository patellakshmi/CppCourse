/*
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
   Created by Lakshmi S. Patel on 14/07/21.
   Copyright (c) 2021, Fight For Education Pvt. Ltd. All rights reserved.
   Please visit us: www.fight4edu.com or www.fight4edu.org
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

#ifndef CPPCOURSE_MINSWAPTOMAKESEQINC_H
#define CPPCOURSE_MINSWAPTOMAKESEQINC_H
#include <iostream>
#include <vector>

class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        /*
        At any index i, min number of swaps to maintain 0 to i in order =
            min(minimum number of swaps required to maintain 0 to i in order by swapping ith numbers,
                minimum number of swaps required to maintain 0 to i in order by not swapping ith numbers)

        if we maintain these 2 variables for every index i, then we can easily find the answer for n.

        Following cases arises:
        1. Numbers are already in order. Swapping again disturbs the order:
           Since, swapping only ith distubs the order, if we need to swap ith, we must also swap i-1th

        2. Numbers are already in order. Swapping again does not matter.
           Since swapping ith again does not matter, if we swap ith, previous numbers can be swapped or
           not swapped. Find the min of 2 cases.
           If we do not swap ith, since i-1th can be swapped or not swapped, find the min of 2 cases.

        3. Numbers are not in order. We must swap to order.
           Since we need to swap ith to make order, i-1th cannot be swapped.

        In the code below,
        prevSwap - min number of swaps by swapping i-1th to keep 0 to i-1 in order
        prevNoSwap - min number of swaps by not swapping i-1th to keep 0 to i-1 in order
        */
        int prevSwap = 1, prevNoSwap = 0;
        for (int i = 1; i<nums1.size(); i++) {
            int curSwap = 0, curNoSwap = 0;

            // case: already in the proper order
            if (nums1[i-1] < nums1[i] && nums2[i-1] < nums2[i]) {

                // case 2: if we swap ith, it do not disturb the order, so find the min of both case
                if (nums1[i] > nums2[i-1] && nums2[i] > nums1[i-1]) {
                    // if we swap ith, i-1th can be swapped or not swapped. In both cases order is maintained;
                    // so find min of the two cases
                    curSwap = min(prevNoSwap, prevSwap) + 1;
                    // if we do not swap the ith, i-1th can be swapped or not swapped
                    curNoSwap = min(prevSwap, prevNoSwap);
                } else {
                    // case 1: if we swap ith, it disturbs the order, so do not swap ith

                    // if we have to swap ith, then we must swap i-1th also to retain the order
                    curSwap = prevSwap + 1;
                    // if we do not swap ith, then nothing to do for i-1th as well; count remains same as prev
                    curNoSwap = prevNoSwap;
                }
            } else {
                // case 3: order is not proper, we must swap the ith element

                // if we swap ith, we must not swap i-1th.
                curSwap = prevNoSwap + 1;
                // if we do not swap ith, i-1th must be swapped to maintain order
                curNoSwap = prevSwap;
            }

            prevSwap = curSwap;
            prevNoSwap = curNoSwap;
        }

        return min(prevSwap, prevNoSwap);
    }
};

#endif //CPPCOURSE_MINSWAPTOMAKESEQINC_H
