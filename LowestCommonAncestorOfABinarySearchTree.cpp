/**
 * @file LowestCommonAncestorOfABinarySearchTree.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2015-07-14
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q){
            return root;
        }
        if (p->val > q->val){
            TreeNode *tem = p;
            p = q;
            q = tem;
        }
        if (root->val < p->val){
            return lowestCommonAncestor(root->right, p, q);
        }
        else if (root->val > q->val){
            return lowestCommonAncestor(root->left, p, q);
        }
        else{
            return root;
        }
    }
};
