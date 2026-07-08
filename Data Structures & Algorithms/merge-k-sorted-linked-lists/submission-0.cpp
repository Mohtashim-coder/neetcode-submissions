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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        // using Min-Heap (Priority Queue)
        // Min-Heap comparator
        auto compare = [](ListNode* a, ListNode* b)
        {
            return a->val > b->val;
        };

        priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> pq(compare);

        // push head of each non-empty list
        for(ListNode* head : lists)
        {
            if(head)
            {
                pq.push(head);
            }
        }

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        while(!pq.empty())
        {
            ListNode* smallest = pq.top();
            pq.pop();

            // add to result
            curr->next = smallest;
            curr = curr->next;

            // push next node from same list
            if(smallest->next)
            {
                pq.push(smallest->next);
            }
        }
        return dummy->next;
    }
};
