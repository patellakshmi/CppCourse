/*
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
   Created by Lakshmi S. Patel on 06/06/21.
   Copyright (c) 2021, Fight For Education Pvt. Ltd. All rights reserved.
   Please visit us: www.fight4edu.com or www.fight4edu.org
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

#ifndef CPPCOURSE_SKYLINE_H
#define CPPCOURSE_SKYLINE_H
#include <iostream>
#include <map>
#include <set>
using namespace std;

class Skyline {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {

        map<int,vector<int>>m;

        for(int i=0;i<buildings.size();i++)
        {
            int l=buildings[i][0];
            int r=buildings[i][1];
            int h=buildings[i][2];

            m[l].push_back(h);
            m[r].push_back(-h);

        }

        multiset<int>s;
        int curr_height=0;
        vector<vector<int>>ans;

        for(auto it=m.begin();it!=m.end();it++)
        {
            for(auto ele:it->second)
                if(ele>0)
                    s.insert(ele);
                else
                    s.erase(s.find(-ele));


            int height;
            if(s.size()>0)
                height = *s.rbegin();
            else
                height = 0;

            if(height!=curr_height)
            {
                vector<int>temp;
                temp.push_back(it->first);
                temp.push_back(height);
                ans.push_back(temp);
            }
            curr_height=height;
        }

        return ans;

    }
};

#endif //CPPCOURSE_SKYLINE_H
