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
    ListNode *swapPairs(ListNode *head) {
        if (head == NULL || head->next == NULL){
            return head;
        }

        ListNode *p1 = head;
        ListNode *p2 = head->next;

        while (p2 != NULL){
            int tem = p1->val;
            p1->val = p2->val;
            p2->val = tem;

            if (p2->next == NULL){
                break;
            }
            else{
                p1 = p1->next->next;
                p2 = p2->next->next;
            }
        }
        return head;

    }
};
