#include<vector>
#include<unordered_set>
using namespace std;

/*
Leetcode #260
Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. 
Find the two elements that appear only once. You can return the answer in any order.

You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.

Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation:  [5, 3] is also a valid answer.

Input: nums = [0,1]
Output: [1,0]
*/

vector<int> singleNumber(vector<int>& nums) {
        
        unordered_set<int> s;
        
        for( int num : nums )
        {
            auto it = s.find(num);
            if( it == s.end() )
                s.insert(num);
            else
                s.erase(it);
        }
        
        vector<int> v;
        for( int num : s )
        {
            v.push_back(num);
        }
        
        return v;
    }
