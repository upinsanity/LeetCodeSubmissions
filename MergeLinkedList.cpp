//Leetcode #21 - Merge two sorted linked lists and return it as a sorted list. The list should be made by splicing together the nodes of the first two lists. 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if(!l1 && !l2)
            return l1;
        
        if(l1&&!l2)
            return l1;
        
        if(l2&&!l1)
            return l2;
        
        ListNode* sortedList=NULL;
        ListNode* currNode=NULL;
        while(l1 && l2)
        {
           if( l1->val < l2->val )
           {
               if(currNode)
                   currNode->next = l1;
               
               currNode=l1;
               l1=l1->next;               
           }
           else
           {
             if(currNode)
               currNode->next = l2;
               
               currNode=l2;
               l2=l2->next;
           }   
            
           if(!sortedList)
               sortedList=currNode;
        }
        
        currNode->next = l1?l1:l2;
        return sortedList;
    }
