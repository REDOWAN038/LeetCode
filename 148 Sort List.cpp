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
    ListNode* merge(ListNode* list1, ListNode* list2){
        ListNode* temp = new ListNode();
        ListNode* curr = temp;

        while(list1 && list2){
            if(list1->val<=list2->val){
                curr->next = list1;
                list1 = list1->next;
            }else{
                curr->next = list2;
                list2 = list2->next;
            }

            curr = curr->next;
        }

        if(list1!=nullptr){
            curr->next = list1;
        }else{
            curr->next = list2;
        }

        return temp->next;
    }

    ListNode* getMiddle(ListNode* head){
        if(head==nullptr || head->next==nullptr){
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* divide(ListNode* head){
        if(head==nullptr || head->next==nullptr){
            return head;
        }

        ListNode* middle = getMiddle(head);

        ListNode* right = middle->next;
        middle->next = nullptr;
        ListNode* left = head;

        left = divide(left);
        right = divide(right);

        return merge(left,right);
    }

    ListNode* sortList(ListNode* head) {
        return divide(head);
    }
};