/*
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
   Created by Lakshmi S. Patel on 04/07/21.
   Copyright (c) 2021, Fight For Education Pvt. Ltd. All rights reserved.
   Please visit us: www.fight4edu.com or www.fight4edu.org
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

#ifndef CPPCOURSE_REMOVE9_H
#define CPPCOURSE_REMOVE9_H

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int newInteger(int n) {
        string res;
        while (n>0){
            int t = n%9 + '0';
            res.push_back(n%9 + '0');
            n /= 9;
        }
        reverse(res.begin(), res.end());
        return stoi(res);
    }
};

#endif //CPPCOURSE_REMOVE9_H
