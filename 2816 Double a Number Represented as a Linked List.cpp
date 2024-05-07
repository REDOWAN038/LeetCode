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
    string multiplyByTwo(string num) {
        int len = num.size();
        string result(len + 1, '0');
        int carry = 0;

        for (int i = len - 1; i >= 0; i--) {
            int product = (num[i] - '0') * 2 + carry;
            result[i + 1] = (product % 10) + '0';
            carry = product / 10;
        }

        if (carry != 0) {
            result[0] = carry + '0';
        } else {
            result.erase(0, 1);
        }

        return result;
    }

    ListNode* doubleIt(ListNode* head) {
        if(head->val==0){
            return head;
        }

        string s = "";
        ListNode* curr = head;

        while(curr){
            int v = curr->val;
            s+=to_string(v);
            curr = curr->next;
        }

        s = multiplyByTwo(s);
        ListNode* res = new ListNode();
        curr = res;

        for(int i=0;i<s.size();i++)
        {
            int v = s[i]-'0';
            ListNode* temp = new ListNode(v);
            curr->next = temp;
            curr = curr->next;
        }

        return res->next;
    }
};