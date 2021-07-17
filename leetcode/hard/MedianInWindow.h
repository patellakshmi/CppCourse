/*
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
   Created by Lakshmi S. Patel on 08/06/21.
   Copyright (c) 2021, Fight For Education Pvt. Ltd. All rights reserved.
   Please visit us: www.fight4edu.com or www.fight4edu.org
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

#ifndef CPPCOURSE_MEDIANINWINDOW_H
#define CPPCOURSE_MEDIANINWINDOW_H
#include <set>
#include <vector>
using namespace std;

class MedianInWindow {
public:

    /*
     * Property: Either left has one more element or left has equal elements as right.
     * Above property, we need to preserve in removal function.
     */
    void remove(multiset<int> &left, multiset<int> &right, int num){

        if( left.empty() ) return;
        if( !left.empty() && right.empty()) {
            left.erase(num);
            return;
        }

        multiset<int>::iterator  lIt,rIt;
        bool foundInLeft = false;
        bool foundInRight = false;

        lIt = left.find(num);
        if( lIt != left.end()){
            foundInLeft = true;
        }

        rIt = right.find(num);
        if( rIt != right.end()){
            foundInRight = true;
        }

        if( left.size() == right.size()){

            if( foundInLeft && foundInRight || foundInRight){
                right.erase(rIt);
            }else{
                left.erase(lIt);
                left.insert(*right.begin());
                right.erase(right.begin());
            }

        }else{

            if( foundInLeft && foundInRight || foundInLeft){
                left.erase(lIt);
            }else{
                right.erase(rIt);
                multiset<int>::iterator locIt = left.end(); locIt--;
                right.insert(*locIt);
                left.erase(locIt);
            }
        }

    }

    /*
     * Property: Either left has one more element or left has equal elements as right.
     * Above property, we need to preserve in insert function.
     */
    void insert(multiset<int> &left, multiset<int> &right, int num){

        if( left.empty() == true){
            left.insert(num);
            return;
        }else if( right.empty() == true){
            multiset<int>::iterator  it = left.end();
            it--;
            if( *it >= num){
                int temp = *it;
                left.erase(it);
                right.insert(temp);
                left.insert(num);
            }else {
                right.insert(num);
            }

            return;
        }

        multiset<int>::iterator  it = left.end(); it--;
        if( left.size() == right.size() ){
            if(  *it >= num) left.insert(num);
            else {
                right.insert(num);
                left.insert(*right.begin());
                right.erase(right.begin());
            }
        }else{
            if( *it >= num){
                int temp = *it;
                left.erase(it);
                right.insert(temp);
                left.insert(num);
            }else {
                right.insert(num);
            }
        }
    }

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        multiset<int> left;
        multiset<int> right;
        multiset<int>::iterator it;
        int i = 0;
        for( ; i < k; i++){ insert(left, right, nums[i]); }
        while( i <= nums.size() ){
            it = left.end();
            it--;
            if( k % 2 == 0 ){
                double baseValue = (*it > *right.begin())? *right.begin(): *it;
                double diff = ((*it < *right.begin())? *right.begin(): *it)-baseValue;
                ans.push_back( (double) baseValue+(double) (diff/2));
            }else{
                ans.push_back(*it);
            }

            if( i == nums.size() ) break;

            remove(left, right, nums[i-k]);
            insert(left, right, nums[i]);

            i++;
        }

        return ans;
    }
};

#endif //CPPCOURSE_MEDIANINWINDOW_H
