/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool ListInBinaryTree(ListNode* head,ListNode* currentNode,TreeNode* root){
        if (currentNode == nullptr) return true;
        if (root == nullptr) return false;
        if (currentNode->val == root->val) {
            currentNode = currentNode->next;
        } else if (head->val == root->val) {
            head = head->next;
        } else {
            currentNode = head;  
        }
        
        return ListInBinaryTree(head, currentNode, root->left) || ListInBinaryTree(head, currentNode, root->right); 
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        bool compare = ListInBinaryTree(head,head,root);
        return compare;
    }
};
