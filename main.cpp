#include <iostream>
#include "algorithm/Util.h"
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <string>
#include <set>
#include <unordered_set>
#include <thread>
#include <list>
#include "data-struct/graph/Graph.h"
#include "data-struct/graph/DetectCycle.h"
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

            initIndex = initIndex+sizeOfWord;
            lastIndex = lastIndex+sizeOfWord;

        }

        return res;
    }
};


int main()
{

    Solution s;
    string string1 = "wordgoodgoodgoodbestword";
    string words = {"foo","bar"};
    vector<string> v;
    v.push_back("good");
    v.push_back("best");
    v.push_back("good");
    v.push_back("word");
    vector<int> res = s.findSubstring(string1, v);
    for(auto a: res){
        cout<< " "<< a;
    }


    return 0;

}