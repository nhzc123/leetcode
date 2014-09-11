/**
 * @file BinaryTreeMaximumPathSum.cpp
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
    int dfs(TreeNode* root , int& result){
        if (root == nullptr){
            return 0;
        }
        int left = max(0, dfs(root -> left, result));
        int right = max(0, dfs(root -> right, result));
        result = max(result, left + right + root -> val);
        return max(left, right) + root -> val;

    }
    int maxPathSum(TreeNode *root) {
        //要想得到最大值， 要么是子树里面有最大值，要么就穿越当前root节点连接左右有最大值
        //因此可以采用自底向上搜索，保存一个全局最大值，递归的时候返回一条边的最大值
        //注意有可能有负数
        int result = 0;
        if (root == nullptr){
            return result;
        }
        result = root -> val;
        dfs (root, result);
        return result;
    }
};
