/**
 * @file ReverseLinkedLists2.cpp
 * @brief
 * @author charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-07
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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        //注意需要是个关键节点，分别是m - 1, m, n , n + 1
        ListNode *before, *start, *end, *after;
        before = start = end = after = NULL;
        ListNode *ptr = head;

        for (int i = 1; i < m; i ++){
            before = ptr;
            ptr = ptr -> next;
        }

        start = end = ptr;

        for (int i = m; i <= n; i ++){
            after = ptr -> next;
            ptr -> next = end;
            end = ptr;
            ptr = after;
        }

        if (before == NULL){//如果从头开始reverse, 则起始点为终点end
            head = end;
        }
        else{//否则将m - 1的位置接到n 那里
            before -> next = end;
        }

        start -> next = after;
        return head;

    }
};
