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
    vector<vector<int>> res;
    vector<int> temp;
    void generatePathSum(TreeNode* root,int currentSum,int targetSum,vector<int> temp){
        temp.push_back(root->val);
        if(currentSum + root->val == targetSum && (root->right==nullptr && root->left==nullptr)){
            res.push_back(temp);
            return;
        }
        if(root->left != nullptr){generatePathSum(root->left,currentSum+root->val,targetSum,temp);}
        if(root->right != nullptr){generatePathSum(root->right,currentSum+root->val,targetSum,temp);}
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root==nullptr){return res;}
        generatePathSum(root,0,targetSum,temp);
        return res;
    }
};
