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
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        /*
        SC = O(m+n)
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* temp = new ListNode(100);
        ListNode* temp3 = temp;
        while(temp1 != NULL && temp2 != NULL)
        {
            if(temp1->val <= temp2->val)
            {
                ListNode* t = new ListNode(temp1->val);
                temp3->next = t;
                temp3 = t;
                temp1 = temp1->next;
            }
            else
            {
                ListNode* t = new ListNode(temp2->val);
                temp3->next = t;
                temp3 = t;
                temp2 = temp2->next;
            }
        }
        if(temp1 == NULL)
        {
            temp3->next = temp2;
        }
        else
        {
            temp3->next = temp1;
        }
        return temp->next;
        */

        //without extra space
        //SC = O(1)

        ListNode* c = new ListNode(100);
        ListNode* temp = c;
        while(a != NULL && b != NULL)
        {
            if(a->val <= b->val)
            {
                temp->next = a;
                a = a->next;
                temp = temp->next;
            }
            else
            {
                
                temp->next = b;
                b = b->next;
                temp = temp->next;
            }
        }
        if(a == NULL) temp->next = b;
        else temp->next = a;
        return c->next;
    }
};