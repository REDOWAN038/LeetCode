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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* tmp = head;
        int cnt=1;
        while(tmp->next){
            cnt+=1;
            tmp = tmp->next;
        }

        if(cnt==1){
            return nullptr;
        }

        if(cnt==n){
            return head->next;
        }

        tmp = head;
        int tar = cnt-n;
        cnt=1;
        while(cnt<tar){
            tmp = tmp->next;
            cnt+=1;
        }
        ListNode* nxt = tmp->next;
        tmp->next = nxt->next;

        return head;
    }
};