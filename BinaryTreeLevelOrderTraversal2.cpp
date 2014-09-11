/**
 * @file BinaryTreeLevelOrderTraversal2.cpp
 * @brief
 * @author charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-08-29
 */

/**
 *  * Definition for binary tree
 *   * struct TreeNode {
 *    *     int val;
 *     *     TreeNode *left;
 *      *     TreeNode *right;
 *       *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *        * };
 *         */
class Solution {
	public:
vector<vector<int> > result;

void levelSearch(TreeNode *root, int level){
    if (root == NULL){
	        return ;
	    }

    if (level == result.size()){
	        vector<int> v;
	        result.push_back(v);
	    }

    result[level].push_back(root -> val);

    levelSearch(root -> left,level + 1);
    levelSearch(root -> right,level + 1);
}

    vector<vector<int> > levelOrderBottom(TreeNode *root) {
	        result.clear();

	        levelSearch(root,0);

	        reverse(result.begin(),result.end());
	        return result;
	    }
;
