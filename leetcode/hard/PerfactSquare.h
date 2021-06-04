//
// Created by Lakshmi S Patel on 24/05/21.
//

#ifndef CPPCOURSE_PERFACTSQUARE_H
#define CPPCOURSE_PERFACTSQUARE_H
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;

        long num;
        int pivot, left = 2, right = x / 2;
        while (left <= right) {
            pivot = left + (right - left) / 2;
            num = (long)pivot * pivot;
            if (num > x) right = pivot - 1;
            else if (num < x) left = pivot + 1;
            else return pivot;
        }

        return right;
    }
};

#endif //CPPCOURSE_PERFACTSQUARE_H
