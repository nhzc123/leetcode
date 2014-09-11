/**
 * @file ValidBinarySearchTree.cpp
 * @brief
 * @author charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-05
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
    bool validTree(TreeNode *root, int minVal, int maxVal){
        if (root == NULL){
            return true;
        }
        if (root -> val <= minVal || root -> val >= maxVal){
            return false;
        }

        return validTree(root -> left, minVal, root -> val) && validTree(root -> right, root -> val, maxVal);
    }

    bool isValidBST(TreeNode *root) {
        //每一颗二叉树检查的时候子树都有一个最大值和最小值，具体数值由递归树传递过来
        return validTree(root, INT_MIN, INT_MAX);
    }
};
