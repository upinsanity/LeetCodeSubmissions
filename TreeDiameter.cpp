/*
Leetcode #543
Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
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

    int getDepth(TreeNode* root, int& diameter)
    {
        if(!root)
            return 0;
        
        int L = getDepth(root->left,diameter);
        int R = getDepth(root->right,diameter);
        
        diameter = max(diameter, L+R+1);
        return (max(L,R)+1);  
    }
    

    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=1;        
        getDepth(root,diameter);
        return diameter-1;        
    }
