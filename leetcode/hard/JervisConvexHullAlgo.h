/*
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
   Created by Lakshmi S. Patel on 02/07/21.
   Copyright (c) 2021, Fight For Education Pvt. Ltd. All rights reserved.
   Please visit us: www.fight4edu.com or www.fight4edu.org
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

#ifndef CPPCOURSE_JERVISCONVEXHULLALGO_H
#define CPPCOURSE_JERVISCONVEXHULLALGO_H
#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:

    int orientation(vector<int> p, vector<int> q, vector<int> r){
        return ( p[1]-q[1])*(q[0]-r[0])-(q[1]-r[1])*(p[0]-q[0]);
    }

    bool inBetween(vector<int> p, vector<int> q, vector<int> r){
        bool x = ( ( q[0] >= p[0] && q[0] <= r[0] )
                   || ( q[0] >= r[0] && q[0] <= p[0]  ) );

        bool y = ( ( q[1] >= p[1] && q[1] <= r[1] )
                   || ( q[1] >= r[1] && q[1] <= p[1]  ) );

        return x && y;
    }

    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {

        set<vector<int>> hull;
        vector<vector<int>> res;

        if( trees.size() < 4){
            for(int i = 0; i < trees.size(); i++)
                res.push_back(trees[i]);
            return res;
        }

        int leftMost = 0;
        for(int i = 0; i < trees.size(); i++){
            if( trees[i][0] < trees[leftMost][0]){
                leftMost = i;
            }
        }

        int p = leftMost;
        do{

            int q = ( p+1 ) % trees.size();
            for(int i = 0; i < trees.size(); i++){
                if( orientation(trees[p], trees[i], trees[q]) < 0 ){
                    q = i;
                }
            }

            for(int i = 0; i < trees.size(); i++){
                if( i != p && i != q
                    && orientation(trees[p], trees[i], trees[q]) == 0
                    && inBetween(trees[p], trees[i], trees[q]) ){
                    hull.insert(trees[i]);
                }
            }

            hull.insert(trees[q]);
            p = q;

        }while( p != leftMost);

        for(vector<int> v: hull){
            res.push_back(v);
        }

        return res;

    }
};

#endif //CPPCOURSE_JERVISCONVEXHULLALGO_H
