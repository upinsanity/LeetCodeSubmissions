/*
Leetcode #846
Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.

Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise.

Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
Output: true

Input: hand = [1,2,3,4,5], groupSize = 4
Output: false

Solution
1. check if size of input is divisible by W, if not return false
2. if yes find n=size/W and initialise vector<stack<int>> v;
3. sort input 
4. put each element in stack if top element diff is 1 && stack size < W, else put in next stack
5. if total no of stack > n return false
6. return true if all stacks are W size
*/

bool isNStraightHand(vector<int> hand, int W) {

        int size = hand.size();
        if (size%W)
            return false;
        int n = size / W;

        map<int, int> m;
        for (int item : hand)
            m[item]++;

        while (!m.empty())
        {
            int item = m.begin()->first;
            for (int i = item; i < item + W; i++)
            {
                if (m.find(i) == m.end())
                    return false;
                map<int, int>::iterator findIt = m.find(i);
                int occ = findIt->second;
                if (occ == 1)
                    m.erase(findIt);
                else
                    m[i]--;
            }
        }
        return true;	
    }
