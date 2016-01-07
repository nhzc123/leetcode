/**
 * @file DeleteNodeinaLinkedList.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2015-07-15
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
    void deleteNode(ListNode* node) {
        if (node == nullptr || node->next == nullptr){
            return;
        }
        ListNode *head = node->next;
        node->val = head->val;
        node->next = head->next;
        delete head;

    }
};
