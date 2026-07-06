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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        // create a dummy node to handle edge cases
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* slow = dummy;
        ListNode* fast = dummy;

        // move fast n step ahed
        for(int i=0; i<=n; i++)
        {
            fast = fast->next;
        }

        // move both pointers until fast reaches end
        while(fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        // remove the nth node from end
        ListNode* temp = slow->next;
        slow->next = temp->next;
        delete temp;

        return dummy->next;
    }
};
