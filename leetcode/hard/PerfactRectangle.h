/*
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
   Created by Lakshmi S. Patel on 15/06/21.
   Copyright (c) 2021, Fight For Education Pvt. Ltd. All rights reserved.
   Please visit us: www.fight4edu.com or www.fight4edu.org
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

#ifndef CPPCOURSE_PERFACTRECTANGLE_H
#define CPPCOURSE_PERFACTRECTANGLE_H

#include <vector>
#include <iostream>
using namespace std;

using pii=pair<int,int>;
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        set<pii> s;
        vector<pii> v(4);
        long long area=0,c=0;
        for(auto a:rectangles){
            v[0]={a[0],a[1]};
            v[1]={a[2],a[3]};
            v[2]={a[0],a[3]};
            v[3]={a[2],a[1]};
            for(auto b:v){
                if(s.find(b)==s.end())
                    s.insert(b);
                else
                    s.erase(b);
            }
            area+=(long long)((a[3]-a[1])*(a[2]-a[0]));
        }
        int i=0;
        if(s.size()==4){
            for(auto a:s){
                v[i]=a;
                i++;
            }
            c=(long long)((v[3].second-v[0].second)*(v[3].first-v[0].first));
            if(area==c)
                return true;
        }
        return false;
    }
};

#endif //CPPCOURSE_PERFACTRECTANGLE_H
