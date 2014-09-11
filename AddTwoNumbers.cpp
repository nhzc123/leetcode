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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head = l1;
        ListNode *pre = l1;
        int carry = 0;
        int cur = 0;
        while (l1 != NULL && l2 != NULL){
            carry += (l1->val + l2->val);
             cur = carry % 10;
            carry /= 10;
            l1->val = cur;
            pre = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != NULL){
            carry += l1->val;
            cur = carry % 10;
            carry /= 10;
            l1->val = cur;
            pre = l1;
            l1 = l1->next;
        }

        if (l2 != NULL){
            pre->next = l2;

        }
        while (l2 != NULL){
            carry += l2->val;
            cur = carry % 10;
            carry /= 10;
            l2->val = cur;
            pre = l2;
            l2 = l2->next;
        }
        if (carry != 0){
            ListNode *tem = new ListNode(carry);
            pre->next = tem;
        }

        return head;
    }
};
