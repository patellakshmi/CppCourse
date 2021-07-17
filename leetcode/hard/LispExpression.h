/*
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
   Created by Lakshmi S. Patel on 14/07/21.
   Copyright (c) 2021, Fight For Education Pvt. Ltd. All rights reserved.
   Please visit us: www.fight4edu.com or www.fight4edu.org
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

#ifndef CPPCOURSE_LISPEXPRESSION_H
#define CPPCOURSE_LISPEXPRESSION_H

#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
    unordered_map<string, stack<int>> m;

    string getVar(const string& expr, int& i) {
        string var;
        while (isalnum(expr[i]))
            var += expr[i++];
        return var;
    }

    int getNum(const string& expr, int& i) {
        int sig = expr[i] == '-' ? -1 : 1;
        if (expr[i] == '-') ++i;
        int val = 0;
        while (isdigit(expr[i]))
            val = expr[i++] - '0' + val * 10;
        val *= sig;
        return val;
    }

    // add / mult
    int getVal(const string& expr, int& i) {
        if (expr[i] == '(')
            return eval(expr, i);
        else if (expr[i] == '-' || isdigit(expr[i]))
            return getNum(expr, i);
        else
            return m[getVar(expr, i)].top();
    }

    int eval(const string& expr, int& i) {
        int s = i;
        while (expr[i] != ' ') ++i;
        string opt(expr.substr(s, i - s));
        ++i; // skip space

        if (opt == "(let") {
            int ans = 0;
            vector<string> vars;
            while (true) {
                // (let x 5 ... (...))
                if (expr[i] == '(') {
                    ans = eval(expr, i);
                    break;
                }

                // (let x 5 ... 99)
                if (expr[i] == '-' || isdigit(expr[i])) {
                    ans = getNum(expr, i);
                    break;
                }

                string var(getVar(expr, i));

                // (let x 5 ... x)
                if (expr[i] == ')') {
                    ans = m[var].top();
                    break;
                }

                ++i; // skip space

                int val = 0;
                if (expr[i] == '(') {
                    val = eval(expr, i);
                } else if (expr[i] == '-' || isdigit(expr[i])) {
                    val = getNum(expr, i);
                } else {
                    val = m[getVar(expr, i)].top();
                }

                vars.push_back(var);
                m[var].push(val);

                ++i; // skip space
            }
            ++i; // skip )
            for (const auto& var : vars)
                m[var].pop();
            return ans;
        } else if (opt == "(add") {
            int l = getVal(expr, i);
            ++i; // skip space
            int r = getVal(expr, i);
            ++i; // skip )
            return l + r;
        } else /*if (opt == "(mult")*/ {
            int l = getVal(expr, i);
            ++i; // skip space
            int r = getVal(expr, i);
            ++i; // skip )
            return l * r;
        }
    }

public:
    int evaluate(string expression) {
        int i = 0;
        if (expression[i] != '(')
            return stoi(expression);
        return eval(expression, i);
    }
};


#endif //CPPCOURSE_LISPEXPRESSION_H
