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

        // using two pointer approach
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr)
        {
            // get mid element
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* righthalf = slow->next;
        slow->next = nullptr; // seperate half list

        // reverse the second half
        ListNode* prev = nullptr;
        ListNode* curr = righthalf;

        while(curr)
        {
            ListNode* nextPtr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextPtr;
        }
        righthalf = prev;

        // merge the two halved
        ListNode* lefthalf = head;

        while(righthalf)
        {
            ListNode* temp1 = lefthalf->next;
            ListNode* temp2 = righthalf->next;

            // Reorder
            lefthalf->next = righthalf;
            righthalf->next = temp1;

            // move pointers
            lefthalf = temp1;
            righthalf = temp2;
        }

    }
};
