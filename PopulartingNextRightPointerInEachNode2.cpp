/**
 * @file PopulartingNextRightPointerInEachNode2.cpp
 * @brief
 * @author charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-01
 */

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL){
            return ;
        }

        TreeLinkNode *left = root -> left;
        TreeLinkNode *right = root -> right;
        TreeLinkNode *next = root -> next;
        //因此，对一个节点需要向右找到第一个节点。
        //对于left，如果right不存在，就在father的next节点去找left/right，依次找下去。
        //对于right，直接在father的next节点开始找。
        if (left != NULL){
            left -> next = right;

            if (right == NULL){

                while (next && left -> next == NULL){
                    left -> next = next -> left;

                    if (left ->next == NULL){
                        left -> next = next -> right;
                    }

                    next = next -> next;
                }
            }

        }

        next = root -> next;

        if (right != NULL){
            while (next && right -> next == NULL){
                right -> next = next -> left;

                if (right -> next == NULL){
                    right -> next = next -> right;
                }

                next = next -> next;
            }


        }


        //因为left需要直接找到right的相关结果，所以递归的时候先递归right
        connect(right);
        connect(left);


    }
};
