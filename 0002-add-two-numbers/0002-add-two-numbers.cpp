class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *temp1 = l1, *temp2 = l2;
        ListNode *head = new ListNode(1);
        ListNode *tail = head;
        int sum, carry = 0;
        while(temp1 && temp2)
        {
            sum = temp1->val + temp2->val + carry;
            tail->next = new ListNode(sum%10);
            temp1 = temp1->next;
            temp2 = temp2->next;
            tail = tail->next;
            carry = sum/10;
        }
        while(temp1)
        {
            sum = temp1->val + carry;
            tail->next = new ListNode(sum%10);
            temp1 = temp1->next;
            tail = tail->next;
            carry = sum/10;
        }
        while(temp2)
        {
            sum = temp2->val + carry;
            tail->next = new ListNode(sum%10);
            temp2 = temp2->next;
            tail = tail->next;
            carry = sum/10;
        }
        while(carry)
        {
            tail->next = new ListNode(carry%10);
            tail = tail->next;
            carry /= 10;
        }
        return head->next;
    }
};