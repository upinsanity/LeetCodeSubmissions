/*
Leetcode #404
Given the root of a binary tree, return the sum of all left leaves.

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
class Solution {
    void sumLeftLeaves(TreeNode* root, int &sum, bool &isLeft)
    {
        if(!root)
            return;
        
        if( isLeft && !root->left && !root->right)
            sum += root->val;
        
        isLeft=true;
        sumLeftLeaves(root->left,sum,isLeft);
        isLeft=false;
        sumLeftLeaves(root->right,sum,isLeft);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        
        int sum = 0;
        bool isLeft=false;
        sumLeftLeaves(root,sum,isLeft);
        return sum;
        
    }
};
