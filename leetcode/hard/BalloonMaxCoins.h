/*
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
   Created by Lakshmi S. Patel on 23/06/21.
   Copyright (c) 2021, Fight For Education Pvt. Ltd. All rights reserved.
   Please visit us: www.fight4edu.com or www.fight4edu.org
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

#ifndef CPPCOURSE_BALLOONMAXCOINS_H
#define CPPCOURSE_BALLOONMAXCOINS_H

//Matrix multiplication
//Correct solution

class Solution {
public:
    int dp[502][502];
    int f(vector<int> &a,int i,int j)
    {
        if(i+1==j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int res=0;
        for(int k=i+1;k<j;k++)
        {
            res=max(res,(f(a,i,k)+f(a,k,j)+a[i]*a[k]*a[j]));
        }
        return dp[i][j] = res;
    }
    int maxCoins(vector<int>& a) {
        a.insert(a.begin(), 1);
        a.insert(a.end(), 1);
        int n=a.size();
        memset(dp,-1,sizeof(dp));
        return f(a,0,n-1);
    }
};


//gready approch - wrong solution
using lit = list<int>::iterator;
using T = pair<int,lit>;

class Compare{
public:
    bool operator()(const T &a, const T &b){
        return a.first > b.first;
    }
};

class Solution {

    list<int> l;
    priority_queue<T, vector<T>, Compare> pq;

public:
    int maxCoins(vector<int>& nums) {
        for(auto x: nums){
            l.push_back(x);
        }
        lit it;
        for( it = l.begin(); it != l.end(); it++){
            pq.push(make_pair(*it,it));
        }

        int res = 0;
        while (!pq.empty()){
            lit it;
            if( l.size() == 1){
                T t = pq.top(); pq.pop();
                res += t.first;
                l.erase(t.second);
            }else if( l.size() == 2){
                T t = pq.top(); pq.pop();
                T s = pq.top(); pq.pop();
                res += t.first*s.first;
                res += ( t.first > s.first) ? t.first: s.first;
                l.erase(t.second);
                l.erase(s.second);
            }else{
                T t = pq.top(); pq.pop();
                int tV = t.first;
                T s = pq.top(); pq.pop();
                int tS = s.first;
                T u = pq.top(); pq.pop();
                int tU = u.first;
                lit lEnd = l.end();
                lEnd--;
                if( t.second == l.begin() || t.second == lEnd ){
                    if( s.second == l.begin() || s.second == lEnd ){
                        it = u.second;
                        int temp = u.first;
                        pq.push(s);
                        pq.push(t);
                    }else{
                        it = s.second;
                        int temp = s.first;
                        pq.push(t);
                        pq.push(u);
                    }
                }else{
                    it = t.second;
                    int temp = t.first;
                    pq.push(s);
                    pq.push(u);
                }

                int m = *it;
                lit next = it; next++;
                lit prev = it; prev--;
                int pV = *prev;
                int nV = *next;

                res += pV * m *nV;

                l.erase(it);
            }
        }

        return res;

    }
};
#endif //CPPCOURSE_BALLOONMAXCOINS_H
