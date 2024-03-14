/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int res;
    int sumOfSubTree(TreeNode* root){
        if(root==nullptr){return 0;}
        if(root->right ==nullptr && root->left==nullptr){return root->val;}
        int left = sumOfSubTree(root->left);
        int right = sumOfSubTree(root->right);
        res += abs(left-right);
        return right + left + root->val;
    }
    int findTilt(TreeNode* root) {
        if(root==nullptr || (root->right ==nullptr && root->left==nullptr)){return 0;}
        int left = sumOfSubTree(root->left);
        int right = sumOfSubTree(root->right);
        res += abs(left-right);
        return res;
    }
};
