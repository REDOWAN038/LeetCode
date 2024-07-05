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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int fo=-1,po=-1,pv=head->val,minn=1000000;
        head = head->next;
        int cnt=2;

        while(head && head->next){
            int cv = head->val;

            if(cv>pv && cv>head->next->val){
                int co = cnt;
                if(fo==-1){
                    fo = cnt;
                    po = cnt;
                }else{
                    minn = min(minn,co-po);
                    po = co;
                }
            }else if(cv<pv && cv<head->next->val){
                int co = cnt;
                if(fo==-1){
                    fo = cnt;
                    po = cnt;
                }else{
                    minn = min(minn,co-po);
                    po = co;
                }
            }

            pv = head->val;
            head = head->next;
            cnt+=1;
        }

        if(fo==po){
            return {-1,-1};
        }else{
            return {minn,po-fo};
        }
    }
};