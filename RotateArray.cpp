#include<vector>
using namespace std;
/*
Leetcode #189

Given an array, rotate the array to the right by k steps, where k is non-negative.
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]

*/

void rotate(vector<int>& nums, int k) {
        
        int len = nums.size();
        if(len<=1)
            return;
        
        if(len==k)
            return;
        
        int currIDx = 0;
        int loopCnt = 0;
        int tempVal = nums[currIDx];	

        while (loopCnt < len)
        {
            int nextIdx = (currIDx + k)%len;
            int nextTempVal = nums[nextIdx];
            nums[nextIdx] = tempVal;

            if (nextIdx == 0)
            {
                nextIdx++;
                tempVal = nums[nextIdx];			
            }
            else
                tempVal = nextTempVal;

            currIDx = nextIdx;
            loopCnt++;
        }
    
    }
