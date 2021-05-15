//
// Created by Lakshmi S Patel on 27/02/21.
//

#ifndef CPPCOURSE_DYNAMICPRG_H
#define CPPCOURSE_DYNAMICPRG_H
#include <string>
#include <iostream>
using namespace std;

namespace dp{
    class DynamicPrg{

        public:
               /* None-Core prg*/
               int min(int a, int b);
               int min(int a, int b, int c);
               int max(int a, int b);

               /* Core Dynamic*/
               int lisInCircularArray(int *arr, int size);
               int lcs(string str1, string str2);
               /*K-Palindrome : by deleting k element string should be palindrome */
               /*To get the logic for this question you should take a help of edit distance question
                * here difference is wrt edit distance is only delete operation allowed here.*/
               int kPalindrome(string str);



               /*Given two string - need to find min edit so that both string are equal
                * operation are: 1. replace 2.insert 3.delete */
               int editDistance(string str1, string str2);


               /*
                ****** Exclusive and inclusive principle ******
                *      Please study well of principle of excl, incl in programming because lot of question is asked
                *      in interview.
                * */

               /*
                * Given time taken by n tasks. Find the minimum time needed to finish the tasks such that skipping of
                * tasks is allowed, but can not skip two consecutive tasks.
                * */

               int minCostWithoutSkipping2(int *arr, int size);

               /*
                * min const to make two string identical, only deletion operation is allowed.
                * there is two way to solve this problem
                * Solution - 1:
                * delete one of character in string 1 and string 2 or both if
                * string at particular index is not identical.
                * recursive relation is dp[i][j] = min( 1+dp[i-1][j], 1+dp[i][j-1], 2+dp[i-1][j-1];
                *
                * Solution -2:
                * just calculate the lcs of both string and and return ( str1.length()-lcs) + ( str2.length()-lcs);
                *
                * */
               int minCost(string str1, string str2 );

               /*
                * minCoins Problem: Given array of coin and a value, we need to get the minimum number of coins
                * to get the value.
                *
                * Idea: Just create on-d array of size sum+1, where dp[0] = 0 means 0 sum we will get with min value
                * for rest of sum that is i= 1... to sum. we will
                * for(int j = 0; j < size; j++){
                *      if( arr[j] <= i){
                *           dp[i] = min(dp[i], dp[i-arr[j]]+1);
                *      }
                *  }
                *
                * */

               int minCoins(int *arr, int size, int sum);

               /*
                * This is standard problem where sum is possible or not
                * */
               bool isSubsetSum(int *arr, int size, int sum);






                /*
                 * All below problems are of kind of matrix multiplication
                 *
                 * */

                /*
                 * Please look this question because it is very important
                 *
                 * */
                void printMinMaxOfExp(string str);

                /*
                 * Below question is very important
                 * */
                int minInsertToPal(string str);

                /*
                 * Longest Even Length Substring such that Sum of First and Second Half is same
                 * */
                int maxRightLeftSumEqual(string str, int n);


                /* This is very important question - please study care full
                 * Modify array to maximize sum of adjacent differences
                 *
                 * Given an array, we need to modify values of this array in such a way that sum
                 * of absolute differences between two consecutive elements is maximized.
                 * If the value of an array element is X, then we can change it to either 1 or X.
                 *
                 * idea: we have two possibility either I can change the value to 1 or arr[i].
                 * We need to maintain the two diamention array one is result of gettting maxium when we change to 1
                 * another is getting the maxinum by changing the variable to element itself.
                 * dp[2][size];
                 * dp[0][i] === > getting the maximum when we change the value to 1.
                 * dp[1][i] === > getting the maximum when we keep the element as it is.
                 *
                 * so recursive relation are below:
                 * dp[o][i] = max( dp[0][i-1]+ 1-1 , dp[1][i-1]+abs(arr[i-1]-1));
                 * dp[1][i] = max( dp[0][i-1] + abs(1-arr[i-1], dp[1][i-1] + abs( arr[i]-arr[i-1]));
                 *
                 *
                 * */

                int maxDiffSum(int *arr, int size);
                int maxDiffSum2(int *arr, int size);

                /*
                 * Ways to write n as sum of two or more positive integers
                 * For a given number n > 0, find the number of different ways in which n can be written as a sum of at two or more positive integers.
                 * */
                int countWays(int n);

                /*Wildcard Pattern Matching
                   Difficulty Level : Hard
                  Last Updated : 23 Oct, 2020
                  Given a text and a wildcard pattern, implement wildcard
                  pattern matching algorithm that finds if wildcard pattern
                  is matched with text. The matching should cover the entire text (not partial text).
                  The wildcard pattern can include the characters ‘?’ and ‘*’
                  ‘?’ – matches any single character
                  ‘*’ – Matches any sequence of characters (including the empty sequence)
                  */

                 /*
                  * Solution: if at jth position  * symbol present in pattern than there are two case,
                  * 1 case: assume * is not present in pattern at jth position
                  * this means we try to match the text upto ith symbol with upto j-1th symbol in pattern
                  * 2 case: if at jth as * matched with ith position in text matched
                  * this means that restult of i-1th and jth should be copied into this place.
                  * */


                 bool isPatternMatched(string text, string pattern){

                 }



    };
}


int dp::DynamicPrg::min(int a, int b, int c){ return min(min(a, b), c); }
int dp::DynamicPrg::min(int a, int b ){ if( a > b ) return b; return a; }
int dp::DynamicPrg::max(int a, int b ){ if( a > b ) return a; return b; }

/*
 * Idea is simple: append the array by itself that is : arr => tempArr = arr . arr
 * Than apply LIS
 * */

int dp::DynamicPrg::lisInCircularArray(int *arr, int size){

    int dp[2*size];
    int tempArr[2*size];

    for(int i = 0; i < size; i++){
        tempArr[i] = arr[i];
        dp[i] = 1;
    }
    for(int i = size; i < 2*size; i++){
        tempArr[i] = arr[i-size];
        dp[i] = 1;
    }

    for(int i = 1; i < 2*size; i++){
        for(int j = 0; j < i; j++){
            if( tempArr[j] < tempArr[i]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }

    int maxValue = INT_MIN;
    for(int i = 0; i < 2*size; i++){
        maxValue = max(maxValue, dp[i]);
    }
    return maxValue;
}

int dp::DynamicPrg::lcs(string str1, string str2){

    int m = str1.length();
    int n = str2.length();

    int dp[m+1][n+1];

    for(int i = 0; i < n+1; i++){
        dp[0][i] = 0;
    }

    for(int i = 0; i < m+1; i++){
        dp[i][0] = 0;
    }

    for(int i = 1; i < m; i++){
        for(int j = 1;  j < n; j ++){
            if( str1[i-1] == str2[j-1] ){
                dp[i][j] = dp[i-1][j-1] +1;
            }else{
                dp[i][j] = max( dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[n][m];
}


/*editDistance function : str1, str2
 * let we are at m, n indexes
 * 1. insert : we inserting a single char in string 1 to make nth char equal so f(m,n) ==> f(m, n-1)
 * 2. delete : we delete a single char in string 1 to go ahead than f(m,n) ==> f(m-1,n)
 * 3. update/replace: if we update or replace the mth char in string 1 for making nth char in string 2 equal
 * so our problem become f(m,n)==>f(m-1,n-1)
 * */

/*This question is similar to longest common subsequence kind of question, please refer that for more help */

int dp::DynamicPrg::editDistance(string str1, string str2){

    int m = str1.length();
    int n = str2.length();

    int dp[m+1][n+1];
    for(int i = 0; i < m+1; i++){
        dp[i][0] = i;
    }

    for(int i = 0; i < n+1; i++){
        dp[0][i] = i;
    }

    for(int i = 1; i < m+1; i++){
        for(int j = 1; j < n+1; j++){
            if( str1[i] == str2[j] ){
                dp[i][j] = dp[i-1][j-1];
            }else{
                dp[i][j] = 1+ min(dp[i-1][j], dp[i][j-1],dp[i-1][j-1]);
            }
        }
    }

    return dp[m][n];
}


/*
 * Here we are delete from both string that is str, and reverse-str
 * so for kPalindrome return of this furnction should be less than 2*k for
 * satisfying k-Palindrome string
 * */
int kPalindrome(string str){

    if( str.size() == 0 ){
        return 0;
    }

    string revStr = "";
    int len = str.length();
    for(int i = 0; i < len; i++){
        revStr = revStr+str[len-i-1];
    }

    int dp[len+1][len+1];
    for(int i = 0; i < len+1; i++){
        dp[i][0] = i;
        dp[0][i] = i;
    }

    for(int i = 1; i < len+1; i++){
        for(int j = 1;  j < len +1 ; j++){
            if( str[i-1] == revStr[j-1] ){
                dp[i][j] = dp[i-1][j-1];
            }else{
                dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
            }
        }

    }

    return dp[len][len];
}


/*
                ****** Exclusive and inclusive principle ******
                *      Please study well of principle of excl, incl in programming because lot of question is asked
                *      in interview.
                * */

/*
 * Given time taken by n tasks. Find the minimum time needed to finish the tasks such that skipping of
 * tasks is allowed, but can not skip two consecutive tasks.
 * */

int dp::DynamicPrg::minCostWithoutSkipping2(int *arr, int size){

    int incl = arr[0];
    int excl = 0;

    int prevIncl;
    int prevExcl;

    for(int i = 1; i < size; i++){
        prevExcl = excl;
        prevIncl = incl;
        incl = min( prevIncl, prevExcl+arr[i]);
        excl = prevIncl;
    }

    return min(incl, excl);
}

int dp::DynamicPrg::minCost(string str1, string str2 ){

    int m = str1.length();
    int n = str2.length();

    int dp[m+1][n+1];

    for(int i = 0; i < m+1; i++){
        dp[i][0] = i;
    }

    for(int j = 0; j < n+1; j++){
        dp[0][j] = j;
    }

    for(int i = 1; i < m+1; i++){
        for(int j = 1; j < n+1; j++ ){
            if( str1[i-1] == str2[j-1] ){
                dp[i][j] = dp[i-1][j-1];
            }else{
                dp[i][j] =  min( 1+dp[i-1][j] , 1+dp[i][j-1] ,2+dp[i-1][j-1]);
            }
        }
    }

    return dp[m][n];
}



int dp::DynamicPrg::minCoins(int *arr, int size, int sum){

    int dp[sum+1];
    dp[0] = 0;
    for(int i = 1; i < sum + 1; i++){
        dp[i] = INT_MAX;
    }

    for(int i = 1; i < sum +1; i++){
        for(int j = 0; j < size; j++){
            if( arr[j] <= i){
                dp[i] = min(dp[i], dp[i-arr[j]]+1);
            }
        }
    }

    if( dp[sum] != INT_MAX) return dp[sum];
    return -1;

}

bool dp::DynamicPrg::isSubsetSum(int *arr, int size, int sum){

    bool dp[sum+1][size+1];
    for(int i = 0; i < size+1; i++){
        dp[0][i] = true;
    }

    for(int i = 1; i < sum+1; i++){
        dp[i][0] = false;
    }

    for(int i = 1; i < sum+1; i++){
        for(int j = 1; j < size+1; j++){
            if( i > arr[j-1]){
                dp[i][j] == dp[i][j-1] || dp[i-arr[j-1]][j-1];
            }
        }
    }

    return dp[sum][size];

}

void dp::DynamicPrg::printMinMaxOfExp(string str){

    int temp = 0;
    vector<int> num;
    vector<char> op;

    for(int i = 0; i < str.length(); i++){

        if( str[i] == '+' || str[i] == '*'){
            op.push_back(str[i]);
            num.push_back(temp);
            temp = 0;

        }else{
            temp = temp*10 + (str[i]-0);
        }
    }

    num.push_back(temp);

    int len = num.size();
    int dpMin[len][len];
    int dpMax[len][len];

    memset(dpMin, 0, sizeof (dpMin));
    memset(dpMax, INT_MAX, sizeof (dpMax));

    for(int i = 0; i < len; i++){
        dpMin[i][i] = num[i];
        dpMax[i][i] = num[i];
    }

    for(int l = 2; l <= len; l++){
        for(int i = 0; i < len-l+1; i++){
            int j = i + l-1;
            for(int k = i; k < j; k++){
                if( op[k] == '+'){
                    dpMin[i][j] = min(dpMin[i][j], dpMin[i][k] +  dpMin[k+1][j] );
                    dpMax[i][j] = max(dpMax[i][j], dpMax[i][k] +  dpMax[k+1][j] );
                }else{
                    dpMin[i][j] = min(dpMin[i][j], dpMin[i][k] *  dpMin[k+1][j] );
                    dpMax[i][j] = max(dpMax[i][j], dpMax[i][k] *  dpMax[k+1][j] );
                }
            }
        }
    }

    cout<< endl;
    cout<< "Min value:: "<< dpMin[0][len-1];
    cout<< endl;
    cout<< "Min value:: "<< dpMin[0][len-1];


}


int dp::DynamicPrg::minInsertToPal(string str){

    int len = str.length();
    if( len == 0 || len == 1) return 0;

    int dp[len][len];
    for(int i = 0; i < len; i++){
        dp[i][i] = 0;
    }

    for(int l = 2; l <= len; l++){
        for(int i = 0; i < len -i+1; i++){
            int j = i+l -1;
            if( str[i] == str[j]){
                dp[i][j] = dp[i+1][j-1];
            }else{
                dp[i][j] = min(dp[i][j-1], dp[i+1][j])+1;
            }
        }
    }

    return dp[0][len];

}


/*
 * O(n^2)
 *
 * */

int dp::DynamicPrg::maxRightLeftSumEqual(string str, int n)
{
    int ans = 0; // Initialize result

    // Consider all possible midpoints one by one
    for (int i = 0; i <= n-2; i++)
    {
        /* For current midpoint 'i', keep expanding substring on
           both sides, if sum of both sides becomes equal update
           ans */
        int l = i, r = i + 1;

        /* initialize left and right sum */
        int lsum = 0, rsum = 0;

        /* move on both sides till indexes go out of bounds */
        while (r < n && l >= 0)
        {
            lsum += str[l] - '0';
            rsum += str[r] - '0';
            if (lsum == rsum)
                ans = max(ans, r-l+1);
            l--;
            r++;
        }
    }
    return ans;
}



/*
 * Time complexity is o(n) and space complexity is o(n)
 * */

int dp::DynamicPrg::maxDiffSum(int *arr, int size){

    int dp[2][size];

    for(int i = 0; i < size; i++){
        dp[0][i] = dp[1][i] = 0;
    }

    for(int i = 1; i < size; i++){
        dp[0][i] = max( dp[0][i-1]+1-1, dp[1][i-1]+ abs(arr[i-1]-1) );
        dp[1][i] = max( dp[0][i-1]+abs(1-arr[i-1]), dp[1][i-1]+ abs( arr[i]-arr[i-1]));
    }

    return max(dp[0][size-1], dp[1][size-1]);

}

/*
 * This is function give the result : time complexity o(n) and space complexity o(1)
 * */
int dp::DynamicPrg::maxDiffSum2(int *arr, int size){

    int changeToOnePrev = 0;
    int noChangePrev = 0;
    int changeToOneCurr = 0;
    int noChangeCurr = 0;

    for(int i = 1; i < size; i++){
        changeToOneCurr = max( changeToOnePrev+1-1, noChangePrev+ abs(arr[i-1]-1) );
        noChangeCurr = max( changeToOnePrev+abs(1-arr[i-1]), noChangePrev+ abs( arr[i]-arr[i-1]));

        changeToOnePrev = changeToOneCurr;
        noChangePrev = noChangeCurr;

    }

    return max(changeToOneCurr, noChangeCurr);

}


// Returns number of ways to write n as sum of
// two or more positive integers
/*
 * This is very important question, please read carefully.
 * It is kind of coins changes problem but before proceed be understand this solution.
 * */
int dp::DynamicPrg::countWays(int n)
{
    // table[i] will be storing the number of
    // solutions for value i. We need n+1 rows
    // as the table is consturcted in bottom up
    // manner using the base case (n = 0)
    int table[n+1];

    // Initialize all table values as 0
    memset(table, 0, sizeof(table));

    // Base case (If given value is 0)
    table[0] = 1;

    // Pick all integer one by one and update the
    // table[] values after the index greater
    // than or equal to n
    for (int i=1; i<n; i++)
        for (int j=i; j<=n; j++)
            table[j] += table[j-i];

    return table[n];
}




#endif //CPPCOURSE_DYNAMICPRG_H
