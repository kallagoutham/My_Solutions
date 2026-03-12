/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> q;
        vector<int> temp;
        vector<vector<int>> res;
        if(root == nullptr){
            return res;
        }
        q.push(root);
        while(!q.empty()){
            int s=q.size();
            temp.clear();
            while(s--){
                Node* node = q.front();
                q.pop();
                for(auto* child : node->children){
                    if(child!=nullptr){
                        q.push(child);
                    }
                }
                temp.push_back(node->val);
            }
            res.push_back(temp);
        }
        return res;
    }
};
