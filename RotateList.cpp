/**
 * @file RotateList.cpp
 * @brief
 * @author charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-08
 */
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
    ListNode *rotateRight(ListNode *head, int k) {
        if (k == 0 || head == NULL || head -> next == NULL){
            return head;
        }

        ListNode *h1 = head;
        ListNode *h2 = head;

        int count = 0;
        ListNode *c = head;
        while (c != NULL){
            count ++;
            c = c -> next;
        }

        k %= count;

        if (k == 0){
            return head;
        }

        while (k){
            h2 = h2 -> next;
            k --;
        }

        ListNode *tail = h2;
        ListNode *h = h1;

        while (h2 != NULL){
            h = h1;
            h1 = h1 -> next;
            tail = h2;
            h2 = h2 -> next;
        }

        h -> next = NULL;
        tail -> next = head;
        return h1;





    }
};
