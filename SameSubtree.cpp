/*
Leetcode #572
Given the roots of two binary trees root and subRoot, return true if there is a subtree
of root with the same structure and node values of subRoot and false otherwise.
A subtree of a binary tree tree is a tree that consists of a node in tree and all of this
node's descendants. The tree tree could also be considered as a subtree of itself.
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
    bool isSame(TreeNode* s, TreeNode* t)
    {
        if(!t && !s)
            return true;
        
        if(s&&!t || !s&&t)
            return false;
        
        return ( s->val == t->val && isSame(s->left,t->left) && isSame(s->right,t->right) );
    }

    bool isSubtree(TreeNode* s, TreeNode* t) {
        
        if(!s || !t)
            return false;
        
        if(s->val == t->val)
        {
            if( isSame(s,t) )
                return true;
        }
        
        return isSubtree(s->left,t) || isSubtree(s->right,t);
    }
