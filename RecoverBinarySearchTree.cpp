/**
 * @file RecoverBinarySearchTree.cpp
 * @brief
 * @author charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-03
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
    TreeNode *node1,*node2,*pre;
    void inOrder(TreeNode *root){
        if (root == NULL){
            return ;
        }

        inOrder(root -> left);

        if (pre != NULL && pre -> val > root -> val){
            node2 = root;
            if (node1 == NULL){
                node1 = pre;
            }
        }

        pre = root;

        inOrder(root -> right);
    }
    void recoverTree(TreeNode *root) {
        //直接中序遍历 先看一个递增序列：1 2 3 4 5 6 7.
        //交换4和6：1 2 3 6 5 4 7
        //注意，6是第一个大于后一个元素的（6 > 5， 5 > 4），4是最后一个小于前一个元素的（5 < 6，4 < 5）。
        //所以在中序遍历的时候有一个pre指针保存之前的指针指向就可以了
        if (root == NULL){
            return ;
        }

        inOrder(root);
        swap(node1 -> val, node2 -> val);
    }
};
