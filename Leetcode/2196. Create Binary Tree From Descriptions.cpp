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
    TreeNode* makeTree(int root,unordered_map<int,pair<int,int>>& m){
        TreeNode* r= new TreeNode(root);
        // if(m.find(root)==m.end()){return nullptr;}
        if(m[root].first!=0){
            r->left=makeTree(m[root].first,m);
        }
        if(m[root].second!=0){
            r->right=makeTree(m[root].second,m);
        }
        m.erase(root);
        return r;
    }
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,pair<int,int>> m;
        set<int> parent;
        for(vector<int> i:descriptions){
            if(i[2]==1){
                m[i[0]].first=i[1];
            }else{
                m[i[0]].second=i[1];      
            }
            parent.insert(i[1]);
        }
        int t;
        for(auto i:m){
            if(parent.find(i.first)==parent.end()){
                t=i.first;
            }
        }
        TreeNode* root=makeTree(t,m);
        return root;
    }
};
