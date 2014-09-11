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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (n == 0 || head == NULL){
            return head;
        }
        ListNode *newNode = new ListNode(head->val + 1);
        ListNode *delNode = newNode;
        ListNode *p1 = head;
        ListNode *p2 = head;
        for (int i = 1; i < n; i++){
            p1 = p1->next;
        }
        while (p2 != NULL){
            if (p1->next == NULL){
                newNode->next = p2->next;
                delete p2;
                break;
            }
            else{
                newNode->next = p2;
                newNode = newNode->next;
                p1 = p1->next;
                p2 = p2->next;
            }

        }
        ListNode *h = delNode;
        h = h->next;
        delete delNode;
        return h;


    }
};
