/**
 * @file CountCompleteTreeNode.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2015-06-10
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int countDepth(TreeNode* root){
        if (root == nullptr){
            return 0;
        }
        return countDepth(root->left) + 1;
    }
    int countNodes(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        int left = countDepth(root->left);
        int right = countDepth(root->right);
        if (left == right){
            return (1 << left) + countNodes(root->right);
        }
        else{
            return (1 << right) + countNodes(root->left);
        }
    }
};
