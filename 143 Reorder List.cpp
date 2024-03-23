class Solution {
public:
    // cur -> Forward
    // head -> Backward
    ListNode *cur;
    void reorderList(ListNode* head) {
        cur = head;
        reorder(head);
    }
    void reorder(ListNode *head){
        //--- Make head reach the end of linklist ---
        if(head == NULL) return;
        reorder(head->next);
        // stop when list reorder if finished
        if(cur == NULL) return;
        //--- Stop when reach middle point ---
        if(head == cur || cur->next == head){
            head->next = NULL; // end the list
            cur = NULL; // denote that reorder is finished
            return;
        }
        //--- Process the nodes ---
        ListNode *nxt = cur->next;
        cur->next = head;
        head->next = nxt;
        cur = nxt;
        return;
    }
};