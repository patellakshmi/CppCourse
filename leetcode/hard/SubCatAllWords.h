//
// Created by Lakshmi S Patel on 18/05/21.
//

#ifndef CPPCOURSE_SUBCATALLWORDS_H
#define CPPCOURSE_SUBCATALLWORDS_H

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {

public:
vector<int> findSubstring(string s, vector<string>& words) {
    map<string,int> wordMap;
    int countWord = words.size();
    int sizeOfWord = words[0].size();
    for(string a: words){
        wordMap[a]++;
    }

    int initIndex = 0;
    int lastIndex = countWord * sizeOfWord;
    map<string,int> sentenceMap;

    vector<int> res;
    while( lastIndex <= s.size()){
        int i = 0;
        sentenceMap.clear();
        while(i < countWord){
            sentenceMap[s.substr(i*sizeOfWord+initIndex, sizeOfWord)]++;
            i++;
        }

        if( sentenceMap == wordMap ){
            res.push_back(initIndex);
        }

        initIndex = initIndex+1;
        lastIndex = lastIndex+1;

    }

    return res;
}
};


#endif //CPPCOURSE_SUBCATALLWORDS_H
