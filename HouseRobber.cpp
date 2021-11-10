#include<vector>
using namespace std;

/*
Leetcode #198
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, 
the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and 
it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can 
rob tonight without alerting the police.

Input: nums = [1,2,3,1]
Output: 4

Input: nums = [2,7,9,3,1]
Output: 12

Solution -
Traverse input and maintain maximum sum for index
Initialize max sum from 0 and 1 
Use maxSum at index-2 and current value to decide current max sum
*/

    int maxOf( int a, int b )
    {
        return (a>b)?a:b;
    }
    
    int rob(vector<int>& nums) {
        
        vector<int> maxSum;
        
        for( int i=0; i<nums.size(); i++ )
        {
            if( i == 0 )
                maxSum.push_back(nums[0]);
            else if( i == 1 )
                maxSum.push_back(maxOf(nums[0],nums[1]));
            else if( i > 1)
            {
               maxSum.push_back(maxOf(maxSum[i-1] , maxSum[i-2]+nums[i]));
            }
        }
        
        return maxSum[nums.size()-1];
    }
