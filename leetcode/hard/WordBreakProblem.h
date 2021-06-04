//
// Created by Lakshmi S Patel on 25/05/21.
//

#ifndef CPPCOURSE_WORDBREAKPROBLEM_H
#define CPPCOURSE_WORDBREAKPROBLEM_H

/*
 * This is very interesting problem
 * if we you go thought recursive approach, it will take longer time longer space.
 * but there is dynamic programming approach.
 *
 *
 */


class Solution {

    vector<string> wordDict;
    bool find(string s){
        for(string x: wordDict){
            if( x == s ) return true;
        }

        return false;
    }

    void makeAllSentence(string s, vector<vector<int>> &index, vector<string>& sentence, int n, string str){
        vector<int> v = index[n];
        for(int x: v){
            if( x == 0){
                str = s.substr(x,n-x+1)+" "+str;
                sentence.push_back(str);
            }else{
                string mystring = str;
                str = s.substr(x,n-x+1)+" "+str;
                makeAllSentence(s, index, sentence, x-1, str);
                str = mystring;
            }
        }

    }

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int size = s.length();
        this->wordDict = wordDict;
        bool dp[size+1];
        vector<vector<int>> index(size);

        memset(dp, false, sizeof(dp));

        for(int i = 1; i <= size; i++){
            string yourstring = s.substr(0,i);
            bool findR = find(yourstring);
            if( findR ){
                index[i-1].push_back(0);
                dp[i] = true;
            }

            if( dp[i] == true ){
                for(int j = i+1; j <=size; j++){
                    string mystring = s.substr(i,j-i);
                    bool findY = find(mystring);
                    if(  findY ){
                        index[j-1].push_back(i);
                        dp[j] = true;
                    }
                }
            }
        }

        /*for(int i = 0; i < index.size(); i++){
            cout<< i << "->";
            for(int j = 0; j < index[i].size(); j++){
                cout<< " "<< index[i][j];
            }
            cout<< endl;
        }*/

        vector<string> sentence;
        makeAllSentence(s, index, sentence, s.size()-1, "");
        /*for(string x: sentence){
            cout<< " "<< x;
            cout<< endl;
        }*/

        return sentence;
    }
};

#endif //CPPCOURSE_WORDBREAKPROBLEM_H
