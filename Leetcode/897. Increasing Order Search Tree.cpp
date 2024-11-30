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
    vector<int> io;
    void inorder(TreeNode* root){
        if(root==nullptr){return;}
        inorder(root->left);
        io.push_back(root->val);
        inorder(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        inorder(root);
        root=new TreeNode(io[0]);
        root->left=nullptr;
        TreeNode* t=root;
        for(int i=1;i<io.size();++i){
            root->right=new TreeNode(io[i]);
            root=root->right;
            root->left=nullptr;
        }
        return t;
    }
};
