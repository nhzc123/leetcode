/**
 * @file PalindromeLinkedList.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2015-07-11
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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr){
            return true;
        }
        ListNode *h1 = head;
        int count = 0;
        while (h1 != nullptr){
            count ++;
            h1 = h1->next;
        }
        ListNode *mid = head;
        int midCount = count / 2;

        while (midCount){
            mid = mid->next;
            midCount --;
        }
        if (count % 2 != 0){
            mid = mid->next;
        }

        ListNode *now = mid;
        ListNode *pre = mid;
        ListNode *next = mid->next;
        mid->next = nullptr;

        while(next != nullptr){
            now = next;
            next = next->next;
            now->next = pre;
            pre = now;
        }

        midCount = count / 2;
        while (midCount){
            if (head->val == now->val){
                head = head->next;
                now = now->next;
                midCount --;
            }
            else{
                return false;
            }
        }
        return true;


    }
};
