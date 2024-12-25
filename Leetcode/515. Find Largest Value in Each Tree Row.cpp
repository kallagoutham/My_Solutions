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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if(root==nullptr){
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        int maxi=INT_MIN;
        int s;
        TreeNode* temp;
        while(!q.empty()){
            s=q.size();
            maxi=INT_MIN;
            for(int i=0;i<s;i++){
                temp=q.front();
                q.pop();
                maxi=max(temp->val,maxi);
                if(temp->left!=nullptr){
                    q.push(temp->left);
                }
                if(temp->right!=nullptr){
                    q.push(temp->right);
                }
            }
            res.push_back(maxi);
        }
        return res;
    }
};
