//
// Created by Lakshmi S Patel on 27/05/21.
//

#ifndef CPPCOURSE_DUPLSTDRTDOP_H
#define CPPCOURSE_DUPLSTDRTDOP_H

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

class Sol {
public:
    int findMin(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        while(low<high)
        {
            while(low<high && nums[low]==nums[low+1]) low++;
            while(low<high && nums[high]==nums[high-1]) high--;

            int mid=(low+high)/2;
            if(nums[mid]>nums[high]) low=mid+1;
            else if(nums[mid]<nums[high]) high=mid;
        }
        return nums[low];
    }

    int findPivot(vector<int>& nums) {  // find pivot in sorted rotated array with distinct elements
        int pivot = -1;
        if(nums[0] < nums[nums.size() - 1]) {
            return pivot;
        }
        int l = 0;
        int h = nums.size() - 1;
        while(l <= h) {
            while(l<h && nums[l]==nums[l+1]) l++;
            while(l<h && nums[h]==nums[h-1]) h--;

            int mid = l + (h - l) / 2;
            if(mid < h && nums[mid] > nums[mid + 1]) {
                return mid;
            } else if(mid > l && nums[mid - 1] > nums[mid]) {
                return mid - 1;
            } else if(nums[mid] >= nums[l]) {
                // go to right half
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return pivot;
    }
};

#endif //CPPCOURSE_DUPLSTDRTDOP_H
