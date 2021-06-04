//
// Created by Lakshmi S Patel on 19/05/21.
//

#ifndef CPPCOURSE_LONGESTVALIDPARENTHESIS_H
#define CPPCOURSE_LONGESTVALIDPARENTHESIS_H
#include <iostream>
#include <map>

using namespace std;

class Solution {
    int max(int a, int b) {
        if( a > b) return a;
        return b;
    }

public:
    int longestValidParentheses(string s) {

        map<int,int> m;
        m[0] = -1;
        int openBracketCount = 0;
        int maxLength = 0;

        for(int i = 0; i < s.length(); i++){
            if( s[i] == ')' and openBracketCount > 0){
                openBracketCount--;
                if( m.find(openBracketCount) != m.end()) {
                    int preIndex = m[openBracketCount];
                    maxLength = max(i-preIndex, maxLength);
                }else {
                    m[openBracketCount] = i;
                }

                map<int, int>::iterator it;
                for(it = m.begin(); it != m.end(); it++ ) {
                    if( it->first > openBracketCount ) {
                        m.erase(it);
                    }
                }

            }else if( s[i] == '(' and openBracketCount >= 0) {
                openBracketCount++;
                m[openBracketCount] = i;

            }else if( s[i] == ')' and openBracketCount == 0){
                m.clear();
                m[0] = i;
            }
        }

        return maxLength;

    }
};

#endif //CPPCOURSE_LONGESTVALIDPARENTHESIS_H
