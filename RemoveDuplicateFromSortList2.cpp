/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL || head->next == NULL){
            return head;
        }
        ListNode *prev = new ListNode(head->val + 1);
        ListNode *h = prev;
        ListNode *cur = head;
        while (cur){
            if (cur->next && cur->val == cur->next->val){
                ListNode *next = cur->next;
                while (next && next->val == cur->val){
                    next = next->next;
                }
                cur = next;
            }
            else{
                prev->next = cur;
                prev = prev->next;
                cur = cur->next;
            }
        }
        prev->next = NULL;
        ListNode *delNode = h;
        h = h->next;
        delete delNode;
        return h;


    }
};
