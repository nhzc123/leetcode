/**
 * @file BalancedBinaryTree.cpp
 * @brief
 * @author charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-08
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
    bool flag;

    int dfs (TreeNode *root){
        if (flag){
            return 0;
        }
        if (root == NULL){
            return 0;
        }
        if (root -> left == NULL && root -> right == NULL){
            return 1;
        }

        int left = dfs(root -> left);
        int right = dfs(root -> right);

        if (abs(left - right) > 1){
            flag = true;
        }

        if (left == NULL){
            return right + 1;
        }
        else if (right == NULL) {
            return left + 1;
        }
        else{
            return max(left, right) + 1;
        }
    }
    bool isBalanced(TreeNode *root) {
        flag = false;

        dfs(root);
        return !flag;
    }
};
