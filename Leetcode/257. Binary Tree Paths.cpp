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
    void BTP(vector<string> &res,string s,TreeNode* root){
        s+=to_string(root->val);
        if(root->left==NULL && root->right==NULL){
            res.push_back(s);
        }
        if(root->left){
            BTP(res,s+"->",root->left);
        }
        if(root->right){
            BTP(res,s+"->",root->right);
        }
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string s="";
        vector<string> res;
        BTP(res,s,root);
        return res;
    }
};
