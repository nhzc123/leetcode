/**
 * @file partitionList.cpp
 * @brief
 * @author charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-08-29
 */

/**
 *  * Definition for singly-linked list.
 *   * struct ListNode {
 *    *     int val;
 *     *     ListNode *next;
 *      *     ListNode(int x) : val(x), next(NULL) {}
 *       * };
 *        */
class Solution {
	public:
    ListNode *partition(ListNode *head, int x) {
	        if (head == NULL || head -> next == NULL){
			            return head;
			        }

	        ListNode *sm_tail = new ListNode(x - 1);
	        ListNode *bg_tail = new ListNode(x + 1);
	        ListNode *sm = sm_tail;
	        ListNode *bg = bg_tail;
	        ListNode *h1 = head;


	        while (h1){
			            if (h1 -> val < x){
						                sm_tail -> next = h1;
						                h1 = h1 -> next;
						                sm_tail = sm_tail -> next;
						                sm_tail -> next = NULL;
						            }
			            else if (h1 -> val >= x){
						                bg_tail -> next = h1;
						                bg_tail = bg_tail -> next;
						                h1 = h1 -> next;
						                bg_tail -> next = NULL;
						            }


			        }

	       sm_tail -> next = bg -> next;


	        return sm -> next;


	    }
};
