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
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* curr = head;
        ListNode* tempNext = NULL;
        
        int j = 1;
        
        ListNode* prev = NULL;
        ListNode* tempPrev = head;
        
        while(j<left)
        {
            if(j==left-1)
                tempPrev=curr;
            curr = curr->next;
            j++;
        }    
        
        tempNext = curr;
        
        ListNode* next = NULL;
        
        while(j<=right)
        {
            next = curr->next;
            curr->next = prev;
            prev= curr;
            curr=next;
            j++;
        }
        
        if(prev && tempPrev)
        tempPrev->next = prev;
        tempNext->next = curr;
        
       
       if(left==1)
            return prev;
        
        return head;
    }
};