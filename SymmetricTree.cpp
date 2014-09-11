/**
 * @file SymmetricTree.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-11
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
    void compared(TreeNode *root, TreeNode *mirror, bool &flag){
        if (!flag){
            return ;
        }
        if (!root && !mirror){
            return;
        }
        if (!root || !mirror){
            flag = false;
            return;
        }
        if (root -> val == mirror -> val){
            compared(root -> left, mirror -> right, flag);
            compared(root -> right, mirror -> left, flag);
            return;
        }
        else{
            flag = false;
            return ;
        }
    }
    bool isSymmetric(TreeNode *root) {
        if (root == nullptr){
            return true;
        }
        TreeNode *mirror = root;
        bool flag = true;
        compared(root, mirror, flag);
        return flag;
    }
};
