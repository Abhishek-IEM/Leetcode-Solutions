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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* temp = head;
        ListNode* temp2 = head;
        int n = 0;
        while(temp != NULL)
        {
            temp = temp->next;
            n++;
        }
        temp = head;
        ListNode* odd = new ListNode(1);
        ListNode* even = new ListNode(2);
        ListNode* o = odd;
        ListNode* e = even;
        while(temp != NULL)
        {
            for(int i=1;i<=n;i++)
            {
                if(i % 2 != 0)
                {
                    o->next = temp;
                    temp = temp->next;
                    o = o->next;
                }
                else
                {
                    e->next = temp;
                    temp = temp->next;
                    e = e->next;
                }
            }
        }
        o->next = even->next;
        e->next = NULL; 
        return odd->next;
    }
};