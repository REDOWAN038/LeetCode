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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,bool>mp;
        for(int v : nums){
            mp[v] = true;
        }

        while(head && mp[head->val]){
            head = head->next;
        }

        ListNode* curr = head->next;
        ListNode* prev = head;

        while(curr){
            if(mp[curr->val]){
                prev->next = curr->next;
                curr = prev->next;
            }else{
                curr = curr->next;
                prev = prev->next;
            }
        }

        return head;
    }
};