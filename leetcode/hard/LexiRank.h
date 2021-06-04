//
// Created by Lakshmi S Patel on 21/05/21.
//

#ifndef CPPCOURSE_LEXIRANK_H
#define CPPCOURSE_LEXIRANK_H

#include <iostream>
#include <map>
#include <vector>
using namespace std;

class LexiRank {
public:
    const int mod = 1e9 + 7;
    long long modpow(long long b, long long p){
        long long ans = 1;
        for (; p; p>>=1){
            if (p&1)
                ans = ans * b%mod;
            b = b * b % mod;
        }
        return ans;
    }
    int makeStringSorted(string s) {
        long long ans = 0;
        map<int, long long> freq;
        for (char& c: s){
            freq[c - 'a']++;
        }
        vector<long long> fact(s.size() + 1, 1ll);
        for (int i = 1; i <= s.size(); i++){
            fact[i] = (fact[i - 1] * i)%mod;
        }
        int l = s.size();
        for (char c: s){
            l--;
            long long t = 0, rev = 1;
            for (int i = 0; i < 26; i++){
                if (i < c - 'a')
                    t += freq[i];
                rev = (rev * fact[freq[i]])%mod;

            }
            ans += (t*fact[l]%mod) * modpow(rev, mod - 2);
            ans %= mod;
            freq[c - 'a']--;
        }
        return ans;
    }
};

class Solution {
public:

    int operation(string &s){

        int size = s.length();
        int i = size-1;
        for(; i>0; i--){
            if( s[i] < s[i-1]){
                break;
            }
        }

        if( i == 0) return 0;

        int targetIndex = i-1;
        int j = size-1;
        for(; j >= i; j--){
            if( s[j] < s[targetIndex]){
                break;
            }
        }

        char ch = s[j];
        s[j] = s[targetIndex];
        s[targetIndex] = ch;

        int start = i;
        int end = size-1;
        while(start < end){
            char ch = s[start];
            s[start] = s[end];
            s[end] = ch;

            start++;
            end--;
        }

        return 1;
    }

    int makeStringSorted(string s) {

        int power = pow(10,9)+7;
        int count = 0;
        while( operation(s)){
            count++;
            //cout<< count << " "<< s<< endl;
            count = count % power;
        }



        return count;

    }
};

class Stats{
public:
    int count = 0;
    map<char, int> m;
};

class LexiRank{

public:
    const int mod = 1e9 + 7;
    Stats countAllLatterComeBefore(string str, int i){
        char ch = str[i];
        Stats charStats;
        for(int j = i; j < str.size(); j++){
            charStats.m[str[j]]++;
            if( str[j] < str[i] ){
                charStats.count++;
            }

        }

        return charStats;
    }

    int makeStringSorted(string str){
        int size = str.size();
        vector<long long> fact(size+1,1ll);
        fact[0] =1;

        int myMod = 1e9+7;

        for(int i = 1; i < size+1; i++ ){
            fact[i] = (i * fact[i-1] )%mod;
        }

        int res = 0;

        for(int i = 0; i < size; i++ ){
            Stats myStat = countAllLatterComeBefore(str, i);
            long long totalWordsForFixedI = (fact[size-i-1]);;
            for(auto e: myStat.m){
                totalWordsForFixedI = totalWordsForFixedI / fact[e.second];
            }
            totalWordsForFixedI = totalWordsForFixedI* myStat.count %mod;
            res += totalWordsForFixedI;
            res %= mod;
        }


        return res;
    }



};

#endif //CPPCOURSE_LEXIRANK_H
