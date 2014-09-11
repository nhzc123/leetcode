/**
 * @file MergeTwoSortedList.cpp
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *head = new ListNode(-1);
        ListNode *ptr = head;

        while (l1 != NULL && l2 != NULL){
            if (l1 -> val < l2 -> val){
                ptr -> next = l1;
                l1 = l1 -> next;
            }
            else{
                ptr -> next = l2;
                l2 = l2 -> next;
            }
            ptr = ptr -> next;
        }

        if (l1 != NULL){
            ptr -> next = l1;
        }
        if (l2 != NULL){
            ptr -> next = l2;
        }

        ptr = head;
        head = head -> next;
        delete ptr;
        return head;

    }
};
