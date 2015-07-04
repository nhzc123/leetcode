/**
 * @file InsertionSortList.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2015-04-23
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
    ListNode *insertionSortList(ListNode *head) {

        if( head == NULL || head->next == NULL){

            return head;
        }

        ListNode *cur = head->next;
        head->next = NULL;

        while( cur != NULL){

            ListNode *tem = head;
            ListNode *next = cur->next;
            ListNode *pre = NULL;

            while( tem != NULL && tem->val <= cur->val){

                pre = tem;
                tem = tem->next;

            }

            if( pre != NULL){
                 if(pre -> next){
                    cur -> next = pre -> next;
                    pre -> next = cur;
                }else
                {
                    pre -> next = cur;
                    cur -> next = NULL;
                }
            }
            else{
                cur->next = head;
                head = cur;

            }

            cur = next;
        }
        return head;


    }
};
