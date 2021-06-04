//
// Created by Lakshmi S Patel on 23/05/21.
//

#ifndef CPPCOURSE_MAXDIFF_H
#define CPPCOURSE_MAXDIFF_H

#include <vector>
#include <iostream>
using namespace std;

/*
 * Maximum difference between two elements such that larger element appears after the smaller number
 */

int maxDiffFromLeft(vector<int>& arr){

   int maxDiff = arr[1] - arr[0];
   int minElement = arr[0];
   for(int i = 1; i < arr.size(); i++){
        if( maxDiff < (arr[i]-minElement)) maxDiff = arr[i] -minElement;
        if( arr[i] < minElement ) arr[i] = minElement;
        return maxDiff;
   }
}

/*
Like min element, we can also keep track of max element from right side.
Thanks to Katamaran for suggesting this approach. Below is the implementation :
*/

int maxDiffFromRight(vector<int>& arr){

    int maxDiff = arr[arr[arr.size()-1]] - arr[arr[arr.size()-12];
    int maxElement = arr[arr.size()-1];
    for(int i = arr.size()-1; i >0 ; i++){
        if( maxDiff < (maxElement - arr[i] )) maxDiff = maxElement - arr[i];
        if( arr[i] < maxElement ) arr[i] = maxElement;
        return maxDiff;
    }
}

/*
 * Maximum profit by buying and selling a share at most twice
 */

// C++ program to find maximum
// possible profit with at most
// two transactions


// Returns maximum profit with
// two transactions on a given
// list of stock prices, price[0..n-1]
int maxProfit(int price[], int n)
{
    // Create profit array and
    // initialize it as 0
    int* profit = new int[n];
    for (int i = 0; i < n; i++)
        profit[i] = 0;

    /* Get the maximum profit with
    only one transaction
    allowed. After this loop,
    profit[i] contains maximum
    profit from price[i..n-1]
    using at most one trans. */
    int max_price = price[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        // max_price has maximum
        // of price[i..n-1]
        if (price[i] > max_price)
            max_price = price[i];

        // we can get profit[i] by taking maximum of:
        // a) previous maximum, i.e., profit[i+1]
        // b) profit by buying at price[i] and selling at
        // max_price
        profit[i]
                = max(profit[i + 1], max_price - price[i]);
    }

    /* Get the maximum profit with two transactions allowed
    After this loop, profit[n-1] contains the result */
    int min_price = price[0];
    for (int i = 1; i < n; i++) {
        // min_price is minimum price in price[0..i]
        if (price[i] < min_price)
            min_price = price[i];

        // Maximum profit is maximum of:
        // a) previous maximum, i.e., profit[i-1]
        // b) (Buy, Sell) at (min_price, price[i]) and add
        // profit of other trans. stored in profit[i]
        profit[i] = max(profit[i - 1],
                        profit[i] + (price[i] - min_price));
    }
    int result = profit[n - 1];

    delete[] profit; // To avoid memory leak

    return result;
}




#endif //CPPCOURSE_MAXDIFF_H
