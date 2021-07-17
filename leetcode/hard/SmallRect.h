/*
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
   Created by Lakshmi S. Patel on 09/06/21.
   Copyright (c) 2021, Fight For Education Pvt. Ltd. All rights reserved.
   Please visit us: www.fight4edu.com or www.fight4edu.org
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

#ifndef CPPCOURSE_SMALLRECT_H
#define CPPCOURSE_SMALLRECT_H
#include <iostream>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
    int minArea(vector<vector<char>> image, int x, int y) {

        set<int> xSet;
        set<int> ySet;


        queue<pair<int,int>> q;
        q.push(make_pair(x,y));
        image[x][y] = '0';

        int xMoves[] ={1,-1,1,-1, 0, 0,-1,1};
        int yMoves[] ={1,1,-1,-1,-1, 1,0,0};

        while(!q.empty()) {

            pair p = q.front(); q.pop();
            //cout<< "{("<<p.first<<")";
            //cout<< "("<<p.second<<")}";
            xSet.insert(p.first);
            ySet.insert(p.second);

            for(int i = 0; i < 8; i++){
                if( p.first+xMoves[i]>=0 && p.first+xMoves[i] < image.size()
                    &&  p.second+yMoves[i] >=0 && p.second+yMoves[i]< image[0].size()                    && image[p.first+xMoves[i]][p.second+yMoves[i]] == '1'){

                    q.push(make_pair(p.first+xMoves[i],p.second+yMoves[i]));
                    image[p.first+xMoves[i]][p.second+yMoves[i]] = '0';

                }
            }
        }


        set<int>::iterator it = xSet.end(); it--;
        //cout<< *it;
        //cout<< *xSet.begin();
        int verLen = *it - *xSet.begin()+1;
        it = ySet.end(); it--;
        //cout<< *it;
        //cout<< *xSet.begin();
        int horLen = *it - *ySet.begin()+1;

        return verLen*horLen;

    }
};

#endif //CPPCOURSE_SMALLRECT_H
