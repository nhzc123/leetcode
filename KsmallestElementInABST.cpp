/**
 * @file KsmallestElementInABST.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2015-07-04
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
// inorder search can be used by the time complexity is O(n)
// we can use the feature of BST and store the left node count of each nodes
// if the node A has N left node, and if K = N + 1 , then A is the Kth smallest
// if K < N, then we can search the Kth smallest in A's left node
// if K > N, then we can search the K - N - 1 smallest in A's right node
    void inOrderSearch(TreeNode *root, int &k, int &result){
        if (k == 0){
            return ;
        }
        if (root == nullptr){
            return ;
        }

        inOrderSearch(root->left, k, result);

        k --;
        if (k == 0){
            result = root->val;
        }

        inOrderSearch(root->right, k, result);

    }
    int kthSmallest(TreeNode* root, int k) {
        int result = 0;

        if (root == nullptr){
            return result;
        }

        inOrderSearch(root, k, result);

        return result;
    }
};
