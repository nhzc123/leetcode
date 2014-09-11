/**
 * @file BinaryTreezigzagLevelOrderTraversal.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-11
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
    void convert(TreeNode *root, vector<vector<int>> &result, int level){
        if (root == nullptr){
            return ;
        }
        if (result.size() == level){
            vector<int> tmp;
            result.push_back(tmp);
        }
        result[level].push_back(root -> val);
        convert(root -> left, result, level + 1);
        convert(root -> right, result, level + 1);
    }
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > result;
        if (root == nullptr){
            return result;
        }
        convert(root, result, 0);
        for (int i = 1; i < result.size(); i = i + 2){
            reverse(result[i].begin(), result[i].end());
        }
        return result;
    }
};
