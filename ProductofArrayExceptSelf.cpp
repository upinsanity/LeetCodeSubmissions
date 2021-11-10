/*
Leetcode #238
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        if(nums.size()<2)
            return nums;
        
        vector<int> left(nums.size(),1);
        vector<int> right(nums.size(),1);
        
        for(int i=1; i<nums.size(); i++)
            left[i]=left[i-1]*nums[i-1];
        
        for(int i=nums.size()-2; i>=0; i--)
            right[i]=right[i+1]*nums[i+1];
        
        for(int i=0; i<nums.size(); i++)
            nums[i]=left[i]*right[i];
        
        return nums;
    }
};
