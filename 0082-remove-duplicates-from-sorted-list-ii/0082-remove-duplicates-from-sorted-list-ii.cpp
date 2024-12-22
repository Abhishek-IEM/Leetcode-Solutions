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
    ListNode* deleteDuplicates(ListNode* head) {
        vector<int> ans;
        ListNode* curr = head;
        while(curr)
        {
            ans.push_back(curr->val);
            curr = curr->next;
        }
        unordered_map<int, int> freq;
        for(int i = 0; i < ans.size(); i++) freq[ans[i]]++;

        ListNode *newHead = new ListNode(0);
        ListNode *temp = newHead;
        vector<int> newAns;
        for(auto x : freq)
        {
            int a = x.first;
            int b = x.second;
            if(b == 1)
            {
                newAns.push_back(a);
            }
        }
        sort(newAns.begin(), newAns.end());
        for(int i = 0; i < newAns.size(); i++)
        {
            temp->next = new ListNode(newAns[i]);
            temp = temp->next;
        }
        return newHead->next;
    }
};