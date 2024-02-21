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
    vector<int> nums;
    void getAllNumbersFormed(TreeNode* root,int currentNumber){
        if(root->right==nullptr && root->left==nullptr){nums.push_back(currentNumber);return;}
        if(root->right!=nullptr){getAllNumbersFormed(root->right,(currentNumber*10)+root->right->val);}
        if(root->left!=nullptr){getAllNumbersFormed(root->left,(currentNumber*10)+root->left->val);}
    }
    int sumNumbers(TreeNode* root) {
        getAllNumbersFormed(root,root->val);
        int sum=0;
        for(int i=0;i<nums.size();i++){sum+=nums[i];}
        return sum;
    }
};
