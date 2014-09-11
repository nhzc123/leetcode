/**
 * @file ConvertSortedArrayToBinarySearchTree.cpp
 * @brief
 * @author charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-02
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
    void binarySearch(vector<int> &num,int start, int end, TreeNode *& root){
        if (start > end){
            return ;
        }

        int mid = (start - end) / 2 + end;

        root = new TreeNode(num[mid]);

        binarySearch(num, start, mid -1, root -> left);
        binarySearch(num, mid + 1, end, root -> right);

    }
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if (num.size() == 0){
            return NULL;
        }
        int len = num.size();
        TreeNode *root = NULL;

        binarySearch(num, 0, len - 1, root);
        return root;

    }
};
