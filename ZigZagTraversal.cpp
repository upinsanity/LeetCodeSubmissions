/*
Leetcode #103
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. 
(i.e., from left to right, then right to left for the next level and alternate between).

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]

*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        
        if(!root)
            return res;
        
        bool left2right=true;        
        queue<TreeNode*> q;
        q.push(root);
        
        vector<int> currNodes;
        
        while(!q.empty())
        {            
            int size = q.size();
            currNodes.clear();
            
            while(size--)
            {
                TreeNode* curr = q.front();
                q.pop();                
                
                currNodes.push_back(curr->val);
                
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);                
            }
            
            if(!left2right)
                reverse(currNodes.begin(),currNodes.end());
            left2right = !left2right ;
            res.push_back(currNodes);                
        }
        
        return res;
    }
