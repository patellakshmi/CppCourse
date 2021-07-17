/*
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
   Created by Lakshmi S. Patel on 01/07/21.
   Copyright (c) 2021, Fight For Education Pvt. Ltd. All rights reserved.
   Please visit us: www.fight4edu.com or www.fight4edu.org
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

#ifndef CPPCOURSE_STROBOGRAMMATIC_H
#define CPPCOURSE_STROBOGRAMMATIC_H


class Solution1 {
public:

    int count = 0;
    int lim = 16;
    long long int l, r;
    string s[5][2] = {{"0","0"},{"1","1"},{"8","8"},{"6","9"},{"9","6"}};
    string empty = "";

    int strobogrammaticInRange(string low, string high) {

        string pre,suf;
        l = convert(low);
        r = convert(high);

        find(empty,s[0][0],empty);
        find(empty,s[1][0],empty);
        find(empty,s[2][0],empty);

        for(int i=1;i<5;i++){
            for(int j=0;j<3;j++){
                find(s[i][0],s[j][0],s[i][1]);
            }
            find(s[i][0],empty,s[i][1]);
        }

        return count;
    }

    void find(string pre, string mid, string suf){
        if(pre.length() + mid.length() + suf.length() >= lim){
            return;
        }

        long long int x = convert(pre+mid+suf);
        if(x >= l && x <= r){
            count++;
        }

        if(x>r || pre.length() == 0 || suf.length() == 0)
            return;

        for(int i=0;i<5;i++){
            find(pre+s[i][0], mid, s[i][1]+suf);
        }
    }

    long long int convert(string s){
        long long int a = 0;
        for(int i=0;i<s.length();i++){
            a = a*10 + s[i]-'0';
        }
        return a;
    }

};

class Solution {
public:
    void backtrack(long long low, long long high, int left, int right, string cur, unordered_set<string> myset, int &cnt)
    {
        if (left > right) {
            long long number = stoll(cur);
            if (number >= low && number <= high)
                cnt++;
            return;
        }

        if (left == right) {
            cur[left] = '0';
            backtrack(low, high, left + 1, right -1, cur, myset, cnt);
            cur[left] = '8';
            backtrack(low, high, left + 1, right - 1, cur, myset, cnt);
            cur[left] = '1';
            backtrack(low, high, left+1, right - 1, cur, myset, cnt);
            return;
        }

        for (auto it : myset) {
            if (left == 0 && it[0] == '0')
                continue;

            cur[left] = it[0];
            cur[right] = it[1];

            backtrack(low, high, left+1, right-1, cur, myset, cnt);
        }
    }

    int strobogrammaticInRange(string low, string high) {
        unordered_set<string> myset;
        int low_size = low.size();
        int high_size = high.size();
        long long high_num = stoll(high);
        long long low_num = stoll(low);
        int cnt = 0;
        int size;

        myset.insert("69");
        myset.insert("11");
        myset.insert("88");
        myset.insert("96");
        myset.insert("00");

        for (size = low_size; size <= high_size; size++) {
            string cur(size, 0);
            backtrack(low_num, high_num, 0, size - 1, cur, myset, cnt);
        }

        return cnt;
    }
};


#endif //CPPCOURSE_STROBOGRAMMATIC_H
