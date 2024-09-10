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
    int gcd(int a,int b){
        if(a==0){
            return b;
        }
        return gcd(b%a,a);
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr = head;

        while(curr && curr->next){
            int val = gcd(curr->val,curr->next->val);
            ListNode* temp = new ListNode(val);
            temp->next = curr->next;
            curr->next = temp;
            curr = temp->next;
        }

        return head;
    }
};