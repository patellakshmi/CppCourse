/*
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
   Created by Lakshmi S. Patel on 02/07/21.
   Copyright (c) 2021, Fight For Education Pvt. Ltd. All rights reserved.
   Please visit us: www.fight4edu.com or www.fight4edu.org
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

#ifndef CPPCOURSE_NONCONSECUTIVEONES0_N_H
#define CPPCOURSE_NONCONSECUTIVEONES0_N_H

#include <iostream>
#include <vector>

class Solution {
public:
    int findIntegers(int num) {
        int *f = new int[32];
        f[0] = 1;
        f[1] = 2;
        for (int i = 2; i < 32; i++)
            f[i] = f[i - 1] + f[i - 2];
        int i = 30, sum = 0, prev_bit = 0;
        while (i >= 0) {
            if ((num & (1 << i)) != 0) {
                sum += f[i];
                if (prev_bit == 1) {
                    //If there is two consecutive 1s than we need to stop
                    //sum and return sum till now.
                    return sum;
                }
                prev_bit = 1;
            } else
                prev_bit = 0;
            i--;
        }
        //if it reach till last bit than f(0) we need to add
        return sum + 1;
    }
};

#endif //CPPCOURSE_NONCONSECUTIVEONES0_N_H
