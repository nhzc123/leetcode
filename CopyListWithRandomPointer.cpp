/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    void copyList(RandomListNode *head){

        if(head != NULL){

            RandomListNode *copyNode = new RandomListNode(head -> label);
            copyNode -> next = head -> next;
            head -> next = copyNode;
            copyList(copyNode -> next);
        }
    }

    void randomNodeAdd(RandomListNode *head){

        if(head != NULL){

            RandomListNode *copyNode = head -> next;
            if(head -> random != NULL){
                copyNode -> random = head -> random -> next;
            }
            randomNodeAdd(copyNode -> next);
        }

    }

    RandomListNode *splitList(RandomListNode *head){

       RandomListNode *CloneHead,*clone,*origin;
         origin=head;
    if(origin)
    {
        CloneHead=origin->next;
        origin->next=CloneHead->next;
        origin=CloneHead->next;
        clone=CloneHead;
    }
    while(origin)
    {
        RandomListNode* temp=origin->next;
        origin->next=temp->next;
        origin=origin->next;
        clone->next=temp;
        clone=temp;
    }
    return CloneHead;
    }


    RandomListNode *copyRandomList(RandomListNode *head) {

        if (head == NULL){

            return NULL;
        }

        RandomListNode *tem = head;
        copyList(tem);
        tem = head;
        randomNodeAdd(tem);

        return splitList(head);

    }
};
