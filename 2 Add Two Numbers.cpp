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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* curr = head;
        int parity = 0;

        while(l1 && l2){
            int val = l1->val + l2->val + parity;
            curr->next = new ListNode(val%10);
            curr = curr->next;
            parity = val/10;
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1){
            int val = l1->val + parity;
            curr->next = new ListNode(val%10);
            curr = curr->next;
            parity = val/10;
            l1 = l1->next;
        }

        while(l2){
            int val = l2->val + parity;
            curr->next = new ListNode(val%10);
            curr = curr->next;
            parity = val/10;
            l2 = l2->next;
        }

        if(parity){
            curr->next = new ListNode(parity);
            curr = curr->next;
        }

        return head->next;
    }
};