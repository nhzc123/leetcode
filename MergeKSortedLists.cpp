/**
 * @file MergeKSortedLists.cpp
 * @brief
 * @author charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-01
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

    ListNode *merge2Lists(ListNode *list1, ListNode *list2){
        ListNode *point1 = list1;
        ListNode *point2 = list2;
        ListNode *tem = new ListNode(INT_MIN);
        ListNode *head = tem;

        while (point1 != NULL && point2 != NULL){
            if (point1 -> val <= point2 -> val){
                tem -> next = point1;
                point1 = point1 -> next;
            }
            else{
                tem -> next = point2;
                point2 = point2 -> next;
            }
            tem = tem -> next;
        }

        if (point1 != NULL){
            tem -> next = point1;
        }

        if (point2 != NULL){
            tem -> next = point2;
        }

        ListNode *delNode = head;
        head = head -> next;
        delete delNode;
        return head;
    }
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode *result;
        if (lists.size() == 0){
            return NULL;
        }

        result = lists[0];

        for (int i = 1; i < lists.size(); i ++){
            result = merge2Lists(result, lists[i]);
        }

        return result;

    }
};
