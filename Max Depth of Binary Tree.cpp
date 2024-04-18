/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::maxDepth(TreeNode* A) {
    if(A==nullptr){
        return 0;
    }
    if(A->left==nullptr && A->right==nullptr){
        return 1;
    }
    return 1+max(maxDepth(A->left),maxDepth(A->right));
}
