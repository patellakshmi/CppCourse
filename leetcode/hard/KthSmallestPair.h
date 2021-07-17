/*
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
   Created by Lakshmi S. Patel on 11/07/21.
   Copyright (c) 2021, Fight For Education Pvt. Ltd. All rights reserved.
   Please visit us: www.fight4edu.com or www.fight4edu.org
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

#ifndef CPPCOURSE_KTHSMALLESTPAIR_H
#define CPPCOURSE_KTHSMALLESTPAIR_H

/*
we have a range in which the difference between the pairs can fall
that is abs(min-max)

*/
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {

        /*
        sorting to be able to efficiently evaluate for a distance d
        how many pairs are there which have distance less than d - in O(n)

        */
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int hi=nums[n-1]-nums[0],lo=0,ans;
        while(lo<=hi)
        {
            int mid=(lo+hi)/2,cnt=0;
            // two pointer technique O(n)
            for(int i=0,j=0;i<n;i++)
            {
                /*
                let's say for a given 'i' we want to find all the pairs it makes with j
                such that the diff is less than mid
                (and we want to do for all 'i's such that all pairs are considered)
                now if for a given 'i' we find a j such that nums[j]-nums[i]>mid
                then there's no point incrementing j as array has been sorted so nums[j] increases
                now all b/w i and j qualify to be second element of the required pair with 'i' being first

                also for next i' we can consider j' starting from prev j as all b/w i and j
                will also qualify to be the second element of the required pair with i' being first
                why?
                nums[j]-nums[i]<mid then
                nums[j]-nums[i+1]<mid as nums is increasing (sorted)

                */
                while(j<n && nums[i]+mid>=nums[j])
                    j++;
                cnt+=j-i-1;
            }
            if(cnt<k)
                lo=mid+1;
            else
            {
                ans=mid;
                hi=mid-1;
            }
        }
        return ans;

    }
};

#endif //CPPCOURSE_KTHSMALLESTPAIR_H
