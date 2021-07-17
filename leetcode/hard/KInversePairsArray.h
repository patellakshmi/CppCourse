/*
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
   Created by Lakshmi S. Patel on 02/07/21.
   Copyright (c) 2021, Fight For Education Pvt. Ltd. All rights reserved.
   Please visit us: www.fight4edu.com or www.fight4edu.org
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

#ifndef CPPCOURSE_KINVERSEPAIRSARRAY_H
#define CPPCOURSE_KINVERSEPAIRSARRAY_H



/*
 * Java - recursion
 *
public class Solution {

    Integer[][] memo = new Integer[1001][1001];
public int kInversePairs(int n, int k) {
        if (n == 0)
            return 0;
        if (k == 0)
            return 1;
        if (memo[n][k] != null)
            return memo[n][k];
        int inv = 0;
        for (int i = 0; i <= Math.min(k, n - 1); i++)
            inv = (inv + kInversePairs(n - 1, k - i)) % 1000000007;
        memo[n][k] = inv;
        return inv;
    }

}

 */





class Solution {

    int min(int a, int b){
        if( a > b) return b;
        return a;
    }

public:
    int kInversePairs(int n, int k) {
        int dp[n+1][k+1];
        for(int i = 0; i < n+1; i++){
            for(int j = 0; j < k+1; j++){
                dp[i][j] = 0;
            }
        }

        for(int i = 1; i < n+1; i++){
            for(int j = 0; j < k+1; j++){
                if( j == 0){
                    dp[i][j] = 1;
                }else{
                    for(int p = 0; p <= min(j, i-1); p++){
                        dp[i][j] = (dp[i][j] + dp[i-1][j-p])%1000000007;
                    }
                }
            }
        }

        return dp[n][k];
    }
};

#endif //CPPCOURSE_KINVERSEPAIRSARRAY_H
