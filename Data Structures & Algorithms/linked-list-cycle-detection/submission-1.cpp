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
    bool hasCycle(ListNode* head) {
        
        // using two pointer approach
        
        ListNode* slow = head;
        ListNode* first = head;

        while(first != nullptr && first->next != nullptr)
        {
            slow = slow->next;
            first = first->next->next;

            if(slow == first)
            {
                return true;
            }
        }
        return false;
    }
};
