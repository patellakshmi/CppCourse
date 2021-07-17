/*
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
   Created by Lakshmi S. Patel on 16/06/21.
   Copyright (c) 2021, Fight For Education Pvt. Ltd. All rights reserved.
   Please visit us: www.fight4edu.com or www.fight4edu.org
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

#ifndef CPPCOURSE_WATERTAP_H
#define CPPCOURSE_WATERTAP_H
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:

    int trapRainWater(vector<vector<int>>& heightMap) {
        auto height=heightMap;
        using T=tuple<int,int,int>;
        priority_queue<T,vector<T>, greater<T>> pq;
        //push all border cells into pq
        int n=heightMap.size(), m=heightMap[0].size();
        for (int i=0; i<n;++i) {
            for (int j=0; j<m; j++) {
                if (i==0 || i==n-1 || j==0 || j == m-1)
                    pq.push({height[i][j],i,j});

            }
        }

        int result=0;
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        while (pq.size()) {
            auto [h,y,x]=pq.top(); //retrieve an entry point with the lowest height
            pq.pop();
            int dy[]{0,0,1,-1}, dx[]={1,-1,0,0};
            for (int i=0; i<4; ++i) {
                int nx=x+dx[i], ny=y+dy[i];
                if ((nx>0 && nx<m-1 && ny > 0 && ny< n-1 && !visited[ny][nx])) {
                    if (height[ny][nx]<height[y][x]) {
                        result+=height[y][x]-height[ny][nx]; //filling the cell to make even with lowest entry point
                        height[ny][nx]=height[y][x];
                    }
                    pq.push({height[ny][nx],ny,nx});
                    visited[ny][nx]=true;
                }
            }
        }
        return result;
    }

};

#endif //CPPCOURSE_WATERTAP_H
