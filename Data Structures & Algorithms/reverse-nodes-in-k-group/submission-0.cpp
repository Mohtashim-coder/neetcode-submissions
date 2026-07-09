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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        // check if we have at least k nodes
        ListNode* temp = head;
        int count = 0;
        while(temp && count < k)
        {
            temp = temp->next;
            count++;
        }

        // if less than k nodes return as it is
        if(count < k)
        {
            return head;
        }

        // Reverse first k nodes
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;
        int reversed = 0;

        while(curr && reversed < k)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            reversed++;
        }

        // recursively reversed the next
        head->next = reverseKGroup(curr, k);
        return prev;
    }
};
