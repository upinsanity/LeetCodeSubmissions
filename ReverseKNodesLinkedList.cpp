/*
Leetcode #25

Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
k is a positive integer and is less than or equal to the length of the linked list. If the number of 
nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
You may not alter the values in the list's nodes, only nodes themselves may be changed.

Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
*/

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

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head)
            return NULL;
        
        int count=k-1;
        ListNode* check=head;
        while(check && count)
        {
            check=check->next;
            count--;
        }
        
        if(!check)
            return head;
        
        count=0;
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* next;
        while( count != k && curr )
        {
            next = curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            count++;
        }
        
        head->next=reverseKGroup(curr,k);
        return prev;
    }
