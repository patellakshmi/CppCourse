/*
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
   Created by Lakshmi S. Patel on 18/02/21.
   Copyright (c) 2021, Fight For Education Pvt. Ltd. All rights reserved.
   Please visit us: www.fight4edu.com or www.fight4edu.org
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

#ifndef CPPCOURSE_DPUTIL_H
#define CPPCOURSE_DPUTIL_H

namespace du{

    class DPUtil{
    public:
        int operator +();
        bool isSubsetSum(int *arr, int size, int sum);
        int maxProfitByCuttingRod(int *prof, int size);
        //int maxSurvival(int A, int B, area X, area Y, area Z,int last, map<pair<int, int>, int>& memo)
        //int getMaxSurvivalTime(int A, int B, area X, area Y, area Z);
        int maxIncrSubSeq(int *arr, int size);
        int maxSumIncrSubSeq(int *arr, int size);
        int max(int a, int b);
        int maxProdIncrSubSeq(int *arr, int size);
    };
}

bool du::DPUtil::isSubsetSum(int *arr, int size, int sum){

    //Allocating 2-D array that is DP.
    bool** dp = new bool*[size+1];
    for(int i = 0; i < size+1; i++){
        dp[i] = new bool[sum+1];
    }

    //Setting base case.
    for(int i = 0; i < size+1; i++ ){
        dp[0][i] = true;
        dp[i][0] = ( i == 0 );
    }

    //Dynamically compute the result at dp[i][j].
    for(int i = 1; i < size+1; i++ ){
        for(int j = 1; j < sum+1; j++){
            if( j < arr[i-1] ){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
        }
    }

    //return final result.
    return dp[size][sum];
}

/*
 * Consider a game, in which you have two types of powers, A and B and there are 3 types of Areas X, Y and Z.
 * Every second you have to switch between these areas, each area has specific properties by which your power
 * A and power B increase or decrease. We need to keep choosing areas in such a way that our survival time is
 * maximized. Survival time ends when any of the powers, A or B reaches less than 0.
 * */

/* This is just recursion program
 * */

/*
int du::DPUtil::maxSurvival(int A, int B, area X, area Y, area Z,
                int last, map<pair<int, int>, int>& memo)
{
    //  if any of A or B is less than 0, return 0
    if (A <= 0 || B <= 0)
        return 0;
    pair<int, int> cur = make_pair(A, B);

    //  if already calculated, return calculated value
    if (memo.find(cur) != memo.end())
        return memo[cur];

    int temp;

    //  step to areas on basis of last chose area
    switch(last)
    {
        case 1:
            temp = 1 + max(maxSurvival(A + Y.a, B + Y.b,
                                       X, Y, Z, 2, memo),
                           maxSurvival(A + Z.a, B + Z.b,
                                       X, Y, Z, 3, memo));
            break;
        case 2:
            temp = 1 + max(maxSurvival(A + X.a, B + X.b,
                                       X, Y, Z, 1, memo),
                           maxSurvival(A + Z.a, B + Z.b,
                                       X, Y, Z, 3, memo));
            break;
        case 3:
            temp = 1 + max(maxSurvival(A + X.a, B + X.b,
                                       X, Y, Z, 1, memo),
                           maxSurvival(A + Y.a, B + Y.b,
                                       X, Y, Z, 2, memo));
            break;
    }

    //  store the result into map
    memo[cur] = temp;

    return temp;
}

//  method returns maximum survival time
int du::DPUtil::getMaxSurvivalTime(int A, int B, area X, area Y, area Z)
{
    if (A <= 0 || B <= 0)
        return 0;
    map< pair<int, int>, int > memo;

    //  At first, we can step into any of the area
    return
            max(maxSurvival(A + X.a, B + X.b, X, Y, Z, 1, memo),
                maxSurvival(A + Y.a, B + Y.b, X, Y, Z, 2, memo),
                maxSurvival(A + Z.a, B + Z.b, X, Y, Z, 3, memo));
}

 */

/*
 * Given a rod of length n inches and an array of prices that contains prices of all
 * pieces of size smaller than n. Determine the maximum value obtainable by cutting up
 * the rod and selling the pieces. For example, if length of the rod is 8 and the values
 * of different pieces are given as following, then the maximum obtainable value is 22
 * (by cutting in two pieces of lengths 2 and 6)

length   | 1   2   3   4   5   6   7   8
--------------------------------------------
price    | 1   5   8   9  10  17  17  20

 */

int du::DPUtil::maxProfitByCuttingRod(int *prof, int size){

    int *dp = new int[size+1];
    dp[0] = 0;

    int maxProfit = INT_MIN;
    for(int i = 1; i < size+1; i++){
        maxProfit = INT_MIN;
        for(int j = 0;  j < i; j++){
            maxProfit = max(maxProfit, prof[j]+dp[i-j-1]);
        }
        dp[i] = maxProfit;

    }

    return dp[size];
}


/*
 * Given a fence with n posts and k colors, find out the number of ways of painting
 * the fence such that at most 2 adjacent posts have the same color.
 * */

int paintingFence(int fences, int colors){

    int dp[2][fences+1];
    //dp[0][x]---> last two have same color
    //dp[1][x]---> last two have diff color

    if( fences == 1 ) return colors;
    if( fences == 0 ) return 0;

    dp[0][2] = colors;
    dp[1][2] = colors*(colors-1);

    for(int i = 3; i < fences+1; i++){
        dp[0][i] = dp[1][i-1];
        dp[1][i] = dp[0][i-1]*(colors-1);
    }

    return dp[0][fences]+dp[1][fences];

}


int du::DPUtil::max(int a, int b){
    if( a > b ) return a;
    return b;
}

int du::DPUtil::maxIncrSubSeq(int *arr, int size){

    int dp[size];
    for(int i = 0; i < size; i++){  dp[i] = 1; }

    for(int i = 1; i < size; i++ ){
        for(int j = 0; j < i ; j++ ){
            if( arr[i] > arr[j] ){
                dp[i] = max( dp[i], 1+dp[j]);
            }
        }
    }
    return dp[size-1];
}

int du::DPUtil::maxSumIncrSubSeq(int *arr, int size){

    int dp[size];
    for(int i = 0; i < size; i++){  dp[i] = arr[i]; }

    for(int i = 1; i < size; i++ ){
        for(int j = 0; j < i ; j++ ){
            if( arr[i] > arr[j] ){
                dp[i] = max( dp[i], arr[i]+dp[j]);
            }
        }
    }

    int maxValue = INT_MIN;

    for (int i = 0; i < size; i++ )
        maxValue = max(maxValue, dp[i]);

    return maxValue;
}


int du::DPUtil::maxProdIncrSubSeq(int *arr, int size){

    int dp[size];
    for(int i = 0; i < size; i++){  dp[i] = arr[i]; }

    for(int i = 1; i < size; i++ ){
        for(int j = 0; j < i ; j++ ){
            if( arr[i] > arr[j] ){
                dp[i] = max( dp[i], arr[i]*dp[j]);
            }
        }
    }

    int maxValue = INT_MIN;
    for (int i = 0; i < size; i++ )
        maxValue = max(maxValue, dp[i]);

    return maxValue;
}

int du::DPUtil::operator+() {
    return 0;
}


#endif //CPPCOURSE_DPUTIL_H
