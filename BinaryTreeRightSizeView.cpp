/**
 * @file BinaryTreeRightSizeView.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2015-04-19
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
    void inOrder(TreeNode *root, vector<vector<int>> &result, int step){
        if (root == NULL){
            return ;
        }
        if (result.size() < step){
            vector<int> tem;
            //tem.push_back(root->val);
            result.push_back(tem);
        }
        result[step - 1].push_back(root->val);
        inOrder(root->left, result, step + 1);
        inOrder(root->right, result, step + 1);

    }
    vector<int> rightSideView(TreeNode *root) {
        vector<vector<int>> result;
        vector<int> tem;
        if (root == NULL){
            result.push_back(tem);
            return tem;
        }
        //tem.push_back(root->val);
        //result.push_back(tem);
        inOrder(root, result, 1);
        for (int i = 0; i < result.size(); i ++){
            tem.push_back(result[i].back());
        }
        return tem;
    }
};
