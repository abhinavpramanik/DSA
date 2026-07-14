// 34. Find First and Last Position of Element in Sorted Array
// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
// If target is not found in the array, return [-1, -1].
// You must write an algorithm with O(log n) runtime complexity.

// Example:

// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
// Example 2:

// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]
// Example 3:

// Input: nums = [], target = 0
// Output: [-1,-1]

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int firstOccurance(vector<int>& nums, int target){
        int low = 0, high = nums.size() - 1;
        int ans = -1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(nums[mid] == target){
                ans = mid;
                high = mid - 1;
            }else if(nums[mid] < target){
                low = mid + 1;
            }else{
                high = mid - 1; 
            }
        }

        return ans;

    }

    int lastOccurance(vector<int>& nums, int target){
        int low = 0, high = nums.size() - 1;
        int ans = -1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(nums[mid] == target){
                ans = mid;
                low = mid + 1;
            }else if(nums[mid] < target){
                low = mid + 1;
            }else{
                high = mid - 1; 
            }
        }

        return ans;

    }

    vector<int> searchRange(vector<int>& nums, int target) {
        
        return {firstOccurance(nums, target), lastOccurance(nums, target)};
    }
};