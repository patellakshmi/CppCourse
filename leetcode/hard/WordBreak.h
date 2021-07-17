/*
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
   Created by Lakshmi S. Patel on 23/06/21.
   Copyright (c) 2021, Fight For Education Pvt. Ltd. All rights reserved.
   Please visit us: www.fight4edu.com or www.fight4edu.org
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

#ifndef CPPCOURSE_WORDBREAK_H
#define CPPCOURSE_WORDBREAK_H

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
private:
    unordered_map<string, vector<string>> prefix_map;


    // Build a prefix map where key is prefix and value is list of words.
    void buildPrefixMap(vector<string>& words) {
        for (auto word : words) {
            for (int i = 0 ; i < word.length(); ++i) {
                string prefix = word.substr(0, i + 1);
                prefix_map[prefix].push_back(word);
            }
        }
    }

    void backtrack(int step, vector<string>& list, vector<vector<string>>& result, int len) {
        if (list.size() == len) {
            result.push_back(list);
            return;
        }
        string prefix = "";
        for (auto word : list)
            prefix += word[step];

        vector<string> wordList = prefix_map[prefix];
        for (auto word : wordList) {
            list.push_back(word);
            backtrack(step+1, list, result, len);
            list.pop_back();
        }
    }

public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        vector<vector<string>> result;
        buildPrefixMap(words);
        for (auto word : words) {
            vector<string> list;
            list.push_back(word);
            backtrack(1, list, result, word.length());
        }
        return result;
    }
};

#endif //CPPCOURSE_WORDBREAK_H
