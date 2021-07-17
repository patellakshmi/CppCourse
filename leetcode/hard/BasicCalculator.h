/*
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
   Created by Lakshmi S. Patel on 05/06/21.
   Copyright (c) 2021, Fight For Education Pvt. Ltd. All rights reserved.
   Please visit us: www.fight4edu.com or www.fight4edu.org
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

#ifndef CPPCOURSE_BASICCALCULATOR_H
#define CPPCOURSE_BASICCALCULATOR_H
#include <queue>
#include <iostream>
using namespace std;


class BasicCalculator{
public:
    bool isDigit(char ch){
        if( ch >= '0' && ch <= '9') return true;
        return false;
    }

    bool isOperator(char ch){
        if( ch == '+' || ch == '-') return true;
        return false;
    }

    int calculate(string s) {

        int i = 0;
        queue<int> oprnd;
        int num = 0;
        int sign = 1;
        while( i < s.size()){

            while(i < s.size() && !isDigit(s[i])) {

                sign = (s[i] == '-') ? -1 : (s[i] == '+') ? 1: sign;

                if (s[i] == '(') {
                    //prepare for recursion
                    int j = i+1;
                    int bracket = 1;
                    string substr = "";
                    while (j < s.size()){
                        if( s[j] == '(') bracket++;
                        if( s[j] == ')') bracket--;
                        if( bracket == 0){
                            break;
                        }
                        substr += s[j];
                        j++;
                    }
                    i = j;
                    int res = calculate(substr);
                    oprnd.push(res*sign);
                } else {
                    i++;
                }
            }

            while(i < s.size() && isDigit(s[i])){
                num = num*10 + (s[i]-'0');
                i++;
            }

            num = num*sign;
            oprnd.push(num);
            sign = 1;
            num = 0;
        }

        num = 0;
        while( !oprnd.empty() ){
            num += oprnd.front();
            oprnd.pop();
        }

        return num;

    }

};

#endif //CPPCOURSE_BASICCALCULATOR_H
