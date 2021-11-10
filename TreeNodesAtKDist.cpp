/*
Leetcode #863
Given the root of a binary tree, the value of a target node target, and an integer k, 
return an array of the values of all nodes that have a distance k from the target node, in any order.

Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

    //Func to get all nodes K dist from root
    void kDistFromRoot(TreeNode* root, int K, vector<int>& Res)
    {
        if(!root || K<0)
            return ;
        
        if(K==0)
        {
            Res.push_back(root->val);
            return;
        }
        
        kDistFromRoot(root->left,K-1,Res);
        kDistFromRoot(root->right,K-1,Res);
    }
    
    //Func to get nodes K dist from target
    int kDistFromTarget(TreeNode* root, TreeNode* target, int K, vector<int>& Res)
    {
        if( !root || K<0 )
            return -1;
        
        if(root==target)
        {
            kDistFromRoot(root,K,Res);
            return 0;
        }
        
        int dL = kDistFromTarget(root->left,target,K,Res);
        if(dL != -1)
        {
            int currDist = dL+1;
            
            if(currDist==K)
                Res.push_back(root->val);
            else
                 kDistFromRoot(root->right,K-dL-2,Res);
            
            return currDist;
                
        }
        else
        {
            int dR = kDistFromTarget(root->right,target,K,Res);
            if(dR != -1)
            {
                int currDist = dR+1;

                if(currDist==K)
                    Res.push_back(root->val);
                else
                    kDistFromRoot(root->left,K-dR-2,Res);
                
                return currDist;
                
            }
        }
        
        return -1;
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> result;
        kDistFromTarget(root,target,K,result);
        return result;
    }
