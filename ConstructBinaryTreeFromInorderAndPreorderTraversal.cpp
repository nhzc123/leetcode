/**
 * @file ConstructBinaryTreeFromInorderAndPreorderTraversal.cpp
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
    int findPosition(vector<int> &v, int val, int start, int end){
        for (int i = start; i <= end; i ++){
            if (v[i] == val){
                return i;
            }
        }

        return -1;
    }

    TreeNode *buildTree(vector<int> &inorder, int inBegin, int inEnd, vector<int> &preorder, int preBegin, int preEnd){
        if (inBegin > inEnd){
            return NULL;
        }

        TreeNode *root = new TreeNode(preorder[preBegin]);
        int index = findPosition(inorder, root -> val, inBegin, inEnd);

        root -> left = buildTree(inorder, inBegin, index - 1, preorder, preBegin + 1, preBegin + index - inBegin);
        root -> right = buildTree(inorder, index + 1, inEnd, preorder, preBegin + index - inBegin + 1, preEnd);

        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.size() == 0 || inorder.size() == 0){
            return NULL;
        }

        return buildTree(inorder, 0, inorder.size() - 1, preorder, 0, preorder.size() - 1);
    }
};
