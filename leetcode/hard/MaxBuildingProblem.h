//
// Created by Lakshmi S Patel on 22/05/21.
//

#ifndef CPPCOURSE_MAXBUILDINGPROBLEM_H
#define CPPCOURSE_MAXBUILDINGPROBLEM_H
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <string>
#include <set>
#include <unordered_set>
#include <thread>
#include <list>
#include <stack>

using namespace std;

class Solution {
public:

    /*
     * This is very interested problem and its solution is also interested
     * ===================================================================
     * we have given constrain for each building - in vector of vector
     * that says height of particular building at max given value.
     * and height of neighbour building is differ by +-1 only.
     * first we add the 1-building with height zero and add last building at max height of n-1
     * though there is vector that height constraint for the last building.
     * we we add the last building when there is already last building building present in our restrictions vector
     * than during calculating the min height from right to left side we will get the given constraint for last
     * building.
     * If the constraint for last building is not in restrictions vector then we can calculate the min value of given
     * last building constraint is same as what given to us.
     *
     * Now we calculate the min height building from left side with gien constraint and similary with right hand side
     * so that each building satisfied given constraint of +-1 height of neighbour building.
     *
     * at end we can calculate the max height by picking two building and try to get the height building in middle of
     * this two building.
     * Let understand first:
     *          /  \
     *        /      \
     *       /         |
     *     /           |
     *    |            |
     *    |            |
     *    |            |
     *     _ _ _ _  _ _
     *
     *     ans = max(h1,h3)+ (distance(h1,h2)-abs(h1-h2))/2
     *
     *
     */


    int maxBuilding(int n, vector<vector<int>>& arr) {
        arr.push_back({1, 0});
        arr.push_back({n, n - 1});
        sort(arr.begin(), arr.end());
        int m = arr.size();

        for (int i = 1; i < m; ++i)
            arr[i][1] = min(arr[i][1], arr[i-1][1] + arr[i][0] - arr[i-1][0]);
        for (int i = m - 2; i >= 0; --i)
            arr[i][1] = min(arr[i][1], arr[i+1][1] + arr[i+1][0] - arr[i][0]);

        int ans = 0, l, h1, r, h2;
        for (int i = 1; i < m; ++i) {
            l = arr[i-1][0], r = arr[i][0], h1 = arr[i-1][1], h2 = arr[i][1];
            ans = max(ans, max(h1, h2) + (r - l - abs(h1 - h2)) / 2);
        }
        return ans;
    }
};

#endif //CPPCOURSE_MAXBUILDINGPROBLEM_H
