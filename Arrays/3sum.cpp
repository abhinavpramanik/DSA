// 3Sum

// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
// Notice that the solution set must not contain duplicate triplets.

 

// Example 1:
// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Explanation: 
// nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
// nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
// nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
// The distinct triplets are [-1,0,1] and [-1,-1,2].
// Notice that the order of the output and the order of the triplets does not matter.

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        //BRUTEFORCE

        // set<vector<int>> st;
        // for(int i=0; i<n ; i++){
        //     for(int j=i+1; j<n ; j++){
        //         for(int k=j+1; k<n ; k++){
        //             if(nums[i] + nums[j] + nums[k] == 0){
        //                 vector<int> temp = {nums[i], nums[j], nums[k]};
        //                 sort(temp.begin(), temp.end());
        //                 st.insert(temp);
        //             }
        //         }
        //     }
        // }
        // vector<vector<int>> result(st.begin() , st.end());

        // return result;

        //BETTER 

        // set<vector<int>> st;

        // for(int i=0; i<n ; i++){
        //     set<int> hashset;
        //     for(int j=i+1; j<n ; j++){
        //         int third = -(nums[i] + nums[j]);
        //         if(hashset.find(third) != hashset.end()){
        //             vector<int> temp = {nums[i], nums[j], third};
        //             sort(temp.begin(), temp.end());
        //             st.insert(temp);
        //         }
        //         hashset.insert(nums[j]);
        //     }
        // }

        // vector<vector<int>> result(st.begin() , st.end());
        // return result;

        //OPTIMAL 
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n ;i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            int j = i+1;
            int k = n-1;

            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum < 0){
                    j++;
                }
                else if(sum > 0){
                    k--;
                }
                else{
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    result.push_back(temp);
                    j++;
                    k--;
                    while(j<k && nums[j] == nums[j-1]) j++;
                    while(j<k && nums[k] == nums[k+1]) k--;
                }
            }
        }
        return result;


    }
};