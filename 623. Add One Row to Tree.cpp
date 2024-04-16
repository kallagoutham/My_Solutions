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
    void insert(TreeNode* node,int depth,int val,int currentDepth){
        if(node==nullptr){return;}
        if(currentDepth == depth-1){
            TreeNode* temp = node->left;
            node->left = new TreeNode(val);
            node->left->left = temp;
            temp=node->right;
            node->right = new TreeNode(val);
            node->right->right=temp;
        }else{
            insert(root->left,depth,val,currentDepth+1);
            insert(root->right,depth,val,currentDepth+1);
        }
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(d==1){
            TreeNode node = new TreeNode(val);
            node->left = root;
            return node;
        }
        insert(root,depth,val,1);
        return root;
    }
};
