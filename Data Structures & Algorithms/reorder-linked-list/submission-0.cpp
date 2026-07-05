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
    void reorderList(ListNode* head) {
        if(!head || !head->next)
        {
            return;
        }

        // find the middle of the list
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // split the list into two halves
        ListNode* second = slow->next;
        slow->next = nullptr;

        // reverse the second half
        ListNode* prev = nullptr;
        ListNode* curr = second;

        while(curr)
        {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        second = prev;

        // merge the two halves
        ListNode* first = head;

        while(second)
        {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;
            
            // Reorder
            first->next = second;
            second->next = temp1;
            
            // Move pointers
            first = temp1;
            second = temp2; 
        }
    }
};
