/*
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
   Created by Lakshmi S. Patel on 03/07/21.
   Copyright (c) 2021, Fight For Education Pvt. Ltd. All rights reserved.
   Please visit us: www.fight4edu.com or www.fight4edu.org
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

#ifndef CPPCOURSE_COURSESCHEDULE3_H
#define CPPCOURSE_COURSESCHEDULE3_H
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](auto& lhs, auto& rhs) { return lhs[1] < rhs[1]; });

        int prefix = 0;
        priority_queue<int> pq;
        for (auto& course : courses) {
            prefix += course[0];
            pq.push(course[0]);
            while (prefix > course[1]) {
                prefix -= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};
#endif //CPPCOURSE_COURSESCHEDULE3_H
