//
// Created by Lakshmi S Patel on 20/05/21.
//

#ifndef CPPCOURSE_MINWINDOWSUBSTR_H
#define CPPCOURSE_MINWINDOWSUBSTR_H

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
    string minWindow(string s, string t) {

        vector<int> freq(128, 0);
        for(char ch: t)
            freq[ch]++;

        int start_idx = 0;
        int end_idx = 0;
        int count = 0; //count of number of chars found
        int min_len = INT_MAX;
        int n = s.length();
        int ans_start_idx;

        /*
         * Understanding the solution quit interesting
         * here just think freq table is our requirement table which is form from t string
         * if we get char from s string which is indicated by end_idx
         * we gather one character what we need so we need to decrease one char the our requirement by one
         * when our requirement is greater then zero mean real requirement then we need to count it.
         *
         * let when we want to remove char that is start_idx
         * we are removing one char from our s that means we need to increase our requirement
         * when our requirement at this moment is zero that means that participate in our counting of char
         * so than we only decrease the counting by one.
         *
         */

        while(end_idx < n) {

            if(freq[s[end_idx++]]-- > 0)
                count++;

            while(count == t.length()) {

                int curr_len = end_idx - start_idx;
                if(min_len > curr_len) {
                    min_len = curr_len;
                    ans_start_idx = start_idx;
                }

                if(freq[s[start_idx++]]++ == 0)
                    count--;
            }

        }

        return min_len == INT_MAX ? "" : s.substr(ans_start_idx, min_len);


    }
};

#endif //CPPCOURSE_MINWINDOWSUBSTR_H
