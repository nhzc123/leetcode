/**
 * @file FlattenBinaryTreeToLinkedTree.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-10
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
    void convert(TreeNode *root){
        if (root == nullptr){
            return ;
        }
        if (root -> left != nullptr){
            convert(root -> left);
            TreeNode *cur = root -> left;
            while (cur -> right != nullptr){
                cur = cur -> right;
            }
            cur -> right = root -> right;
            root -> right = root -> left;
            root -> left = nullptr;
        }
        if (root -> right != nullptr){
            convert(root -> right);
        }
    }
    void flatten(TreeNode *root) {
        convert(root);

    }
};
