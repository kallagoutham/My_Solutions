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
    int res=0;
    int dir=-1;
    void sum(TreeNode* root,int dir){
        if(root==nullptr){
            return ;
        }
        if(root->left==nullptr && root->right==nullptr){
            if(dir==0){
                res+=root->val;
            }
        }
        sum(root->left,0);
        sum(root->right,1);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        sum(root,-1);
         return res;
        
    }
};
