/**
 * @file ReverseNodesInKGroup.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-24
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
    ListNode *reverseKGroup(ListNode *head, int k) {
        //递归解法
        if (head == nullptr || k == 1){
            return head;
        }
        int len = 0;
        ListNode *count = head;
        while(count != nullptr){
            count = count -> next;
            len ++;
        }
        //当不足k个的时候，不逆转直接返回
        if (len < k){
            return head;
        }
        ListNode *cur = head -> next;
        ListNode *next = head;
        //逆转k个
        for (int i = 0; i < k - 1; i ++){
            ListNode *post = cur -> next;
            cur -> next = next;
            next = cur;
            cur = post;
        }
        //将k个后面的数传递过去继续逆转
        head -> next = reverseKGroup(cur, k);
        return next;
    }
};
