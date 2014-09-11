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
    void reorderList(ListNode *head) {

        if( head == NULL || head -> next == NULL){
            return ;
        }

        ListNode *p1 = head;
        ListNode *p2 = head;

        //find the second list
        while( p1 -> next != NULL && p1 -> next -> next != NULL){

            p1 = p1 -> next -> next;
            p2 = p2 -> next;
        }

        ListNode *p = p2 -> next;
        p2 -> next = NULL;
        ListNode *previous = NULL;

        // reverse the second list
        while( p  != NULL){

            ListNode * tem = p -> next;
            p -> next = previous;
            previous = p;
            p = tem;
        }

        p = previous;

        ListNode *head1 = head;

        while( head1 != NULL && p != NULL){

            ListNode *next = p -> next;
            p -> next = head1 -> next;
            head1 -> next = p;
            head1 = p -> next;
            p = next;
        }



    }
};
