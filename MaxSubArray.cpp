#include<vector>
using namespace std;
/*
Leetcode #53
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

A subarray is a contiguous part of an array.

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

Solution - 
Traverse the input
Keep a variable to store the maxSofar for cumulative sum
At any point, if the cumulative sum begins to reduce than prev maxSoFar, reset maxSoFar to current number being read
Return maxSum which is the greatest value of maxSoFar obtained
*/

int maxOf(int a,int b){ return a>b?a:b; }
    int maxSubArray(vector<int>& nums) {
        
        int maxSum=nums[0];
        int maxSoFar=nums[0];        
               
        for(int i=1; i<nums.size(); i++)
        {
            maxSoFar = maxOf(nums[i], maxSoFar+nums[i]);
            if(maxSum<maxSoFar)
                maxSum=maxSoFar;
        }        
        return maxSum;
    }
