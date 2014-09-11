/**
 * @file ConvertSortedListToBinarySearchTree.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-11
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *convert(ListNode *head, ListNode *tail){
        if (head == tail){
            return new TreeNode(head -> val);
        }
        ListNode *mid = head;
        ListNode *ptr = head;
        ListNode *pre = head;
        while (ptr != nullptr && ptr -> next != nullptr){
            pre = mid;
            mid = mid -> next;
            ptr = ptr -> next -> next;
        }
        TreeNode *root = new TreeNode(mid -> val);
        if (head != nullptr){
            pre -> next = nullptr;
            root -> left = convert(head, pre);
        }
        if (mid -> next != nullptr)
            root -> right = convert(mid -> next, tail);
        return root;

    }
    TreeNode *sortedListToBST(ListNode *head) {
        if (head == nullptr){
            return nullptr;
        }
        if (head -> next == nullptr){
            return new TreeNode(head -> val);
        }
        ListNode *tail = head;
        while (tail -> next != nullptr){
            tail = tail -> next;
        }
        return convert(head, tail);

    }
};
