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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> temp;
        vector<vector<int>> res;
        if(root == nullptr){
            return res;
        }
        q.push(root);
        bool dir = true;
        while(!q.empty()){
            int s=q.size();
            temp.clear();
            while(s--){
                TreeNode* node = q.front();
                q.pop();
                if(node->left != nullptr){
                    q.push(node->left);
                }
                if(node->right != nullptr){
                    q.push(node->right);
                }
                temp.push_back(node->val);
            }
            if(!dir){
                reverse(temp.begin(),temp.end());
            }
            dir = !dir;
            res.push_back(temp);
        }
        return res;

    }
};
