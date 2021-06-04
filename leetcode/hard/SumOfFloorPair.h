//
// Created by Lakshmi S Patel on 22/05/21.
//

#ifndef CPPCOURSE_SUMOFFLOORPAIR_H
#define CPPCOURSE_SUMOFFLOORPAIR_H
#include <vector>

using namespace std;

class Solution {
public:
    int findLocation(vector<int> nums, int idx1, int idx2, int ele){

        /*
        if( idx1 == idx2 && nums[idx2] == ele){
            return idx2;
        }else if(idx1 == idx2 && nums[idx2] != ele ){
            return -1;
        }

        int mid = (idx1+idx2)/2;
        if( nums[mid] == ele){
            return findLocation(nums, idx1, mid, ele);
        }

        return findLocation(nums, mid, idx2, ele);
         */

        while(true){

            if( idx1 == idx2 && nums[idx2] == ele) return idx2;
            else if(idx1 == idx2 && nums[idx2] != ele ) return -1;
            else if(idx1+1 == idx2 && nums[idx1] != ele) return idx2;

            int mid = (idx1+idx2)/2;

            if( nums[mid] == ele) idx2 = mid;
            else  idx1 = mid;

        }

    }


    int sumOfFlooredPairs(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int res = 0;

        for(int i = 0; i < nums.size(); i++){
            int ele = nums[i];
            int j = findLocation(nums, 0,i, ele);
            if( j != -1){
                for(int k = j; k < nums.size(); k++){
                    int next = nums[k];
                    res = res + next/ele;
                }
            }
        }

        return res;

    }
};


#endif //CPPCOURSE_SUMOFFLOORPAIR_H
