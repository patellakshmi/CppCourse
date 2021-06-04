//
// Created by Lakshmi S Patel on 20/05/21.
//

#ifndef CPPCOURSE_NEXTBIGGERNUM_H
#define CPPCOURSE_NEXTBIGGERNUM_H

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

    void swap(char &a, char &b){
        int temp = a;
        a = b;
        b = temp;
    }

public:
    int nextGreaterElement(int k) {
        if( k < 10 ) return -1;
        string str = to_string(k);
        int n = str.size();

        int i = n-1;
        while( i > 0 && str[i] <= str[i-1]) i--;
        i--;

        if( i == -1) return -1;

        int j = n-1;
        while( j > i && str[i] >= str[j]) j--;


        swap(str[i], str[j]);

        int start = i+1;
        int end = n-1;
        while( start < end){
            swap(str[start], str[end]);
            start++;
            end--;
        }

        int res;
        try{
            res= stoi(str);
        }catch(exception e){
            return -1;
        }
        return res;

    }
};


#endif //CPPCOURSE_NEXTBIGGERNUM_H
