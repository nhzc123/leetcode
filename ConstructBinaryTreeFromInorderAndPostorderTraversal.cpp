/**
 * @file ConstructBinaryTreeFromInorderAndPostorderTraversal.cpp
 * @brief
 * @author charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-04
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
    //由中序遍历和后续遍历可以确定一个二叉树
    //直接递归处理就可以了，现在postorder中找到各个子树的根 然后在inorder中找到根的位置，就是该根的左右节点
    int findPosition(vector<int> &inorder, int value, int start, int end){
        for (int i = start; i <= end; i ++){
            if (inorder[i] == value){
                return i;
            }
        }
        return -1;
    }

    TreeNode *buildTree(vector<int> &inorder, int inBegin, int inEnd, vector<int> &postorder, int poBegin, int poEnd){
        if (inBegin > inEnd){
            return NULL;
        }

        TreeNode *root = new TreeNode(postorder[poEnd]);
        int index = findPosition(inorder, root -> val, inBegin, inEnd);

        root -> left = buildTree(inorder, inBegin, index - 1, postorder, poBegin, poBegin + index - inBegin - 1 );
        root -> right = buildTree(inorder, index + 1, inEnd, postorder, poBegin + index - inBegin, poEnd - 1);

        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.size() == 0 || postorder.size() == 0){
            return NULL;
        }
        return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
};
