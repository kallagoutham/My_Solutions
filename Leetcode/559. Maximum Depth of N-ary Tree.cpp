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
    int maxDepth(Node* root) {
        if (!root) return 0;

        int levels = 0;
        queue<Node*> Q; Q.push(root);

        while (!Q.empty()) {
            size_t size = Q.size();
            levels++;
            for (int _ = 0; _ < size; _++) {
                Node* curr = Q.front(); Q.pop();
                for (Node*& child : curr->children) Q.push(child);
            }
        }

        return levels;
    }
};
