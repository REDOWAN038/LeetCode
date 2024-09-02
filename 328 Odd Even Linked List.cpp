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
        ListNode* oddHead = new ListNode(-1);
        ListNode* evenHead = new ListNode(-1);
        ListNode* odd = oddHead;
        ListNode* even = evenHead;
        ListNode* curr = head;
        bool isOdd = true;

        while(curr){
            ListNode* temp = curr;
            curr = curr->next;
            temp->next = nullptr;

            if(isOdd){
                odd->next = temp;
                odd = odd->next;
                isOdd = false;
            }else{
                even->next = temp;
                even = even->next;
                isOdd = true;
            }
        }

        odd->next = evenHead->next;
        return oddHead->next;
    }
};