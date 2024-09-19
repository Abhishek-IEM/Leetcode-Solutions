class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* Next;

        int count = 0;

        ListNode* check = head;
        for (int i = 0; i < k; i++) {
            if (check == NULL) {
                return head;  // Not enough nodes to reverse, return the original head
            }
            check = check->next;
        }

        while(curr != NULL && count < k)
        {
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
            count++;
        }
        if(Next != NULL)
            head->next = reverseKGroup(Next, k);

        return prev;
    }
};