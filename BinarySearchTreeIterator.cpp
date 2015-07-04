/**
 * @file BinarySearchTreeIterator.cpp
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
class BSTIterator {
public:
    //中序遍历 但是需要用到h 空间复杂度 所以先保存左子树  然后每次弹出的时候再导入该节点右子树的左子树
    stack<TreeNode *> stk;
    BSTIterator(TreeNode *root) {
        while(!stk.empty()){
            stk.pop();
        }
        while(root){//初始化把所有左节点压进去 中序遍历
            stk.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stk.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *tmp = stk.top();
        stk.pop();
        int result = tmp->val;
        tmp = tmp->right;
        while(tmp){
            stk.push(tmp);
            tmp = tmp->left;
        }
        return result;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
