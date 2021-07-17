/*
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
   Created by Lakshmi S. Patel on 12/07/21.
   Copyright (c) 2021, Fight For Education Pvt. Ltd. All rights reserved.
   Please visit us: www.fight4edu.com or www.fight4edu.org
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

#ifndef CPPCOURSE_MINWINDOWSUBSEQ_H
#define CPPCOURSE_MINWINDOWSUBSEQ_H

class Solution1 {
public:
    string minWindow(string s1, string s2) {
        int i,j,len1=s1.length(),len2=s2.length(),id1=0,id2=0,len=INT_MAX,start=-1;
        if(!len1 || !len2)return "";
        while(id1<len1){
            if(s1[id1]==s2[id2])id2++;
            if(id2==len2){
                int last=id1+1;
                while(--id2>=0){
                    while(s1[id1--]!=s2[id2]);
                }
                id1++;
                id2++;
                if(last-id1 < len){
                    len=last-id1;
                    start=id1;
                }
            }
            id1++;
        }
        return start==-1? "":s1.substr(start,len);
    }
};


class Solution {
public:
    string minWindow(string S, string T) {
        int low = 0;
        int high = 0;

        if (T.length() > S.length()) {
            return "";
        }
        if (T == S) {
            return T;
        }

        string result = "";
        int maxLen = S.length();

        while(high < S.length()) {
            int i=0;
            while(high<S.length() && i<T.length()) {
                if(S[high] == T[i]) {
                    i++;
                }
                high++;
                low++;
            }

            if(i!=T.length())
                return result;

            high--;
            low--;
            i--;

            while(low>=0 && i>=0) {
                if(S[low] == T[i]) {
                    i--;
                }
                low--;
            }

            low+=1;
            if(high-low+1 < maxLen) {
                result = S.substr(low, high-low+1);
                maxLen = high-low+1;
            }

            high = ++low;
            low = high;
        }
        return result;
    }
};

#endif //CPPCOURSE_MINWINDOWSUBSEQ_H
