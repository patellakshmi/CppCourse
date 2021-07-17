/*
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
   Created by Lakshmi S. Patel on 25/06/21.
   Copyright (c) 2021, Fight For Education Pvt. Ltd. All rights reserved.
   Please visit us: www.fight4edu.com or www.fight4edu.org
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

#ifndef CPPCOURSE_POORPIGS_H
#define CPPCOURSE_POORPIGS_H
#include <iostream>
using namespace std;

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int state = minutesToTest / minutesToDie + 1;
        return ceil(log(buckets) / log(state));
    }
};

#endif //CPPCOURSE_POORPIGS_H
