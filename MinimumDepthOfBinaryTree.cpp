/**
 * @file MinimumDepthOfBinaryTree.cpp
 * @brief
 * @author charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-07
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

    int minDepth(TreeNode *root) {
       if (root == NULL){
           return 0;
       }
       if (root -> left == NULL && root -> right == NULL){
           return 1;
       }

       int left = minDepth(root -> left);
       int right = minDepth(root -> right);

       if (left == 0){
           return right + 1;
       }
       else if (right == 0){
           return left + 1;
       }
       else{
        return min(left, right) + 1;
       }

    }
};
