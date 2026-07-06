/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if(!head)
        {
            return nullptr;
        }

        // Map original nodes to their copies
        unordered_map<Node*, Node*> map;

        // Pass 1: create all nodes
        Node* curr = head;
        while(curr)
        {
            map[curr] = new Node(curr->val);
            curr = curr->next;
        }

        // Pass 2: Set next and random pointers
        curr = head;
        while(curr)
        {
            map[curr]->next = map[curr->next];
            map[curr]->random = map[curr->random];
            curr = curr->next;
        }
        return map[head];
    }
};
