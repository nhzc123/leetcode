/**
 * @file UniqueBinarySearchTrees2.cpp
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
    vector<TreeNode *> generate(int start, int end){
        vector<TreeNode *> result;
        if (start > end){
            result.push_back(nullptr);
            return result;
        }
        for (int k = start; k <= end; k ++){
            vector<TreeNode *> left = generate(start, k - 1);
            vector<TreeNode *> right = generate(k + 1, end);
            for (int i = 0; i < left.size(); i ++){
                for (int j = 0; j < right.size(); j ++){
                    TreeNode *root = new TreeNode(k);
                    root -> left = left[i];
                    root -> right = right[j];
                    result.push_back(root);
                }
            }
        }
        return result;
    }
    vector<TreeNode *> generateTrees(int n) {
        return generate(1, n);
    }
};
