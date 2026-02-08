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
    int Height(TreeNode* r){
        if(!r)
            return 0;
        return max(Height(r->left),Height(r->right)) +1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        int l=Height(root->left);
        int r=Height(root->right);
        bool lb=isBalanced(root->left);
        bool rb=isBalanced(root->right);
        bool d= abs(l-r)<=1;
        return d&& lb&&rb;
    }
};
