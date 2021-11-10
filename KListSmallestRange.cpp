/*
Leetcode #632
You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.

We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.

Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
Output: [20,24]

Explanation: 
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].
*/
    typedef struct
    {
        int val;
        int listIdx;
        int itemIdx;
    }item;
    
    struct compare
    {
        bool operator() (item a,item b)
        {
            return a.val > b.val;
        }
    };

    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        int minDiff = INT_MAX;
        int maxVal = 0;
        vector<int> out;
        
        priority_queue<item, vector<item>, compare> q;
        for(int i=0; i<nums.size(); i++)
        {
            item x;
            x.val = nums[i][0];
            x.listIdx=i;
            x.itemIdx=0;
            
            if(maxVal<x.val)
                maxVal=x.val;
            
            q.push(x);
        }
        
        while(!q.empty())
        {
            item curr = q.top();
            q.pop();
            
            int range = maxVal - curr.val;
            if( minDiff>range )
            {
                minDiff = range;
                out.clear();
                out.push_back(curr.val);
                out.push_back(maxVal);
            }           
            
           //get next item to push in queue		
            if (curr.itemIdx < nums[curr.listIdx].size()-1)
            {
                item next;
                next.listIdx = curr.listIdx;
                next.itemIdx = curr.itemIdx + 1;
                next.val = nums[next.listIdx][next.itemIdx];
                if (next.val > maxVal)
                    maxVal = next.val;
                q.push(next);
            }
            else
                break;
        }
        
        return out;
    }
