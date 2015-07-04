/**
 * @file IntersectionOfTwoLinkedList.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-11-30
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr){
            return nullptr;
        }
        int lengthA = 0;
        int lengthB = 0;
        ListNode *next = headA;
        ListNode *preA = headA;

        while ( next != nullptr){
            preA = next;
            next = next -> next;
            lengthA ++;
        }

        next = headB;
        ListNode *preB = headB;
        while ( next != nullptr){
            preB = next;
            next = next -> next;
            lengthB ++;
        }

        if (preB != preA){
            return nullptr;
        }

        preB = headB;
        preA = headA;

        if (lengthA > lengthB){
            int count = lengthA - lengthB;
            while (count != 0){
                preA = preA -> next;
                count --;
            }
        }
        else{
            int count = lengthB - lengthA;
            while (count != 0){
                preB = preB -> next;
                count --;
            }
        }

        while (preA != preB){
            preA = preA -> next;
            preB = preB -> next;
        }

        return preA;




    }
};
