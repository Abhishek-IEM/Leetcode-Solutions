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
        if(!head) return NULL;

        unordered_map<Node*, Node*> mp;

        Node* newHead = new Node(head->val);
        Node *oldTemp = head->next, *newTemp = newHead;
        
        mp[head] = newHead; 

        while(oldTemp != NULL)
        {
            Node *copyNode = new Node(oldTemp->val);
            mp[oldTemp] = copyNode;
            newTemp->next = copyNode;
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }
        oldTemp = head; newTemp = newHead;
        while(oldTemp != NULL)
        {
            newTemp->random = mp[oldTemp->random];
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }
        return newHead;
    }
};