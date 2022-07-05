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
    void reverseLL(ListNode **head) {
        ListNode *curr = *head;
        ListNode *prevNode = NULL;
        ListNode *nextNode;
        
        while(curr) {
            nextNode = curr->next;
            curr->next = prevNode;
            prevNode = curr;
            curr = nextNode;
        }
        
        *head = prevNode;
        
    }
    
    int pairSum(ListNode* head) {
        int len = 0;
        
        ListNode* temp = head;
        
        while(temp)
        {
            len++;
            temp= temp->next;
        }
        
        int half_way = (len)/2;
        
        int idx  =0;
        
        ListNode* half;
        
        temp = head;
        
        while(1)
        {
            if(idx+1 == half_way)
            {
                half = temp->next;
                temp->next = nullptr;
                break;
            }
            idx++;
            temp=temp->next;
        }
        reverseLL(&half);
        int ans = 0;
        
        while(head)
        {
            ans=max(ans, (head->val+half->val));
            
            head= head->next;
            half =  half->next;
        }
        
        return ans;
    }
};