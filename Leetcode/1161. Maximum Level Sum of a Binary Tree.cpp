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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int res=1;
        int level=1;
        int sum=root->val;
        while(!q.empty()){
            int size=q.size();
            int temp=0;
            while(size--){
                TreeNode* t=q.front();
                temp+=t->val;
                if(t->right!=nullptr){
                    q.push(t->right);
                }
                if(t->left!=nullptr){
                    q.push(t->left);
                }
                q.pop();
            }
            if(sum<temp){
                sum=temp;
                res=level;
            }
            level++;
        }
        return res;
    }
};
