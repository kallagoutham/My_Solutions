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
    vector<string> strings;
    void generateAllStrings(TreeNode* node,string temp){
        if(node==nullptr){return;}
        if(node->left==nullptr && node->right==nullptr){
            string t=temp;
            reverse(t.begin(),t.end());
            strings.push_back(t);
        }
        if(node->left!=nullptr){
            temp.push_back(char(node->left->val + 97));
            generateAllStrings(node->left,temp);
            temp.pop_back();
        }
        if(node->right!=nullptr){
            temp.push_back(char(node->right->val + 97));
            generateAllStrings(node->right,temp);
            temp.pop_back();
        }
        return;
    }
    string smallestFromLeaf(TreeNode* root) {
        string t="";
        if(root==nullptr){return t;}
        t.push_back(char(root->val+97));
        generateAllStrings(root,t);
        sort(strings.begin(),strings.end());
        if(strings.size()>0){
            return strings[0];
        }
        return "";
    }
};
