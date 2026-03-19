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
    bool findTarget(TreeNode* root, int k) {
        set<int> s;
        TreeNode* node;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            node = q.front();
            if(s.contains(k-node->val)){
                return true;
            }
            s.insert(node->val);
            if(node->right){
                q.push(node->right);
            }
            if(node->left){
                q.push(node->left);
            }
            q.pop();
        }
        return false;
    }
};
