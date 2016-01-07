/**
 * @file LowestCommonAncestorOfABinaryTree.cpp
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
 /*
 如果当前节点为空或者与目标节点之一相同，则返回当前节点

递归寻找p和q在左右子树中的位置

如果p和q分别位于root的左右两侧，则root为它们的LCA，否则为左子树或者右子树
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q){
            return root;
        }
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        return !left ? right : !right ? left : root;
    }
};
