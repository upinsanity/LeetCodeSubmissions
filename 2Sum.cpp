#include<vector>
using namespace std;

/*
Leetcode #1
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].
*/
vector<int> twoSum(vector<int>& nums, int target) {
        
        map<int,int> m;
        vector<int> output;
        for( int i=0; i<nums.size(); i++ )
        {
            int num = nums[i];
            auto it = m.find(num);
            if( it == m.end() )
                m[target-num]=i;
            else
            {
                output.push_back(m[num]);
                output.push_back(i);
                m.erase(it);
            }  
        }
        
        return output;
    }
