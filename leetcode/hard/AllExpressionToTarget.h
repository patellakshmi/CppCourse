/*
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
   Created by Lakshmi S. Patel on 08/06/21.
   Copyright (c) 2021, Fight For Education Pvt. Ltd. All rights reserved.
   Please visit us: www.fight4edu.com or www.fight4edu.org
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

#ifndef CPPCOURSE_ALLEXPRESSIONTOTARGET_H
#define CPPCOURSE_ALLEXPRESSIONTOTARGET_H

// C++ program to find all possible expression which
// evaluate to target
#include <bits/stdc++.h>
using namespace std;

// Utility recursive method to generate all possible
// expressions
void getExprUtil(vector<string>& res, string curExp,
                 string input, int target, int pos,
                 int curVal, int last)
{
    // true if whole input is processed with some
    // operators
    if (pos == input.length())
    {
        // if current value is equal to target
        //then only add to final solution
        // if question is : all possible o/p then just
        //push_back without condition
        if (curVal == target)
            res.push_back(curExp);
        return;
    }

    // loop to put operator at all positions
    for (int i = pos; i < input.length(); i++)
    {
        // ignoring case which start with 0 as they
        // are useless for evaluation
        if (i != pos && input[pos] == '0')
            break;

        // take part of input from pos to i
        string part = input.substr(pos, i + 1 - pos);

        // take numeric value of part
        int cur = atoi(part.c_str());

        // if pos is 0 then just send numeric value
        // for next recurion
        if (pos == 0)
            getExprUtil(res, curExp + part, input,
                        target, i + 1, cur, cur);


            // try all given binary operator for evaluation
        else
        {
            getExprUtil(res, curExp + "+" + part, input,
                        target, i + 1, curVal + cur, cur);
            getExprUtil(res, curExp + "-" + part, input,
                        target, i + 1, curVal - cur, -cur);
            getExprUtil(res, curExp + "*" + part, input,
                        target, i + 1, curVal - last + last * cur,
                        last * cur);
        }
    }
}

// Below method returns all possible expression
// evaluating to target
vector<string> getExprs(string input, int target)
{
    vector<string> res;
    getExprUtil(res, "", input, target, 0, 0, 0);
    return res;
}

// method to print result
void printResult(vector<string> res)
{
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
}


/*
 * Another solution but the best solution to get the ans.
 * Really this is one of awesome approche to solve any problem.
 *
 *
 */
class Solution {
public:
    vector<string> ans;
    string buf;
    long t;
    int last;

    vector<string> addOperators(string num, int target) {
        buf.resize(20);
        t = target;
        last = num.size()-1;

        dfs(num, 0, 0, 0, 0, '+');

        return ans;
    }

    void dfs(string& num, int i, int j, long sum, long sumtmp, char prevop){
        long v = 0;

        for (int k = i ; ; k++){
            v *= 10;
            v += long(num[k]-'0');
            buf[j] = num[k];
            j++;

            long sumtmptmp = (prevop == '*'?sumtmp*v: (prevop == '+'?sumtmp+v:sumtmp-v));

            if (k == last){
                if (sum+sumtmptmp == t) ans.push_back(buf.substr(0, j));

                return;
            }

            buf[j] = '*';
            dfs(num, k+1, j+1, sum, sumtmptmp, '*');
            buf[j] = '+';
            dfs(num, k+1, j+1, sum+sumtmptmp, 0, '+');
            buf[j] = '-';
            dfs(num, k+1, j+1, sum+sumtmptmp, 0, '-');

            if (!v) return;
        }
    }

};

// Driver code to test above methods
int driver()
{
    string input = "123";
    int target = 6;
    vector<string> res = getExprs(input, target);
    printResult(res);

    input = "125";
    target = 7;
    res = getExprs(input, target);
    printResult(res);
    return 0;
}


#endif //CPPCOURSE_ALLEXPRESSIONTOTARGET_H
