class Solution {
public:
    Node* flatten(Node* head) {
        if(!head) return head;

        Node *curr = head;

        while(curr)
        {
            if(curr->child != NULL)
            {
                Node *next = curr->next;
                curr->next = flatten(curr->child);

                curr->next->prev = curr;
                curr->child = NULL;

                while(curr->next) curr = curr->next;

                if(next)
                {
                    curr->next = next;
                    next->prev = curr;
                }
            }
            curr = curr->next;
        }
        return head;
    }
};