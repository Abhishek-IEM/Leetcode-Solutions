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
    ListNode* rotateRight(ListNode* head, int k) {
       if(head == NULL || head->next == NULL) return head;
       ListNode *temp = head;
       int count = 0;
       while(temp)
       {
            count++;
            temp = temp->next;
       }
       vector<int> ans;
       temp = head;
       while(temp)
       {
            ans.push_back(temp->val);
            temp = temp->next;
       }
       temp = head;
       k = k % count;
       int i = count - k;
       while(i < count)
       {
            temp->val = ans[i];
            i++;   
            temp = temp->next; 
       }
       int j = 0;
       while(j < count - k)
       {
         temp->val = ans[j];
         j++;
         temp = temp->next;
       }
       return head;
    }
};