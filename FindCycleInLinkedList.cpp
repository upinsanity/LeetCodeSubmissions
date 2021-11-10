//Leetcode #141 - Given head, the head of a linked list, determine if the linked list has a cycle in it.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {        
        
        ListNode* curr=head;
        ListNode* curr2x=head;
        
        while(curr)
        {
            curr=curr->next;
            if(curr2x && curr2x->next)
            {   
                curr2x=curr2x->next->next;

                if(curr==curr2x)
                    return true;
            }
        }
        
        return false;
    }
};
