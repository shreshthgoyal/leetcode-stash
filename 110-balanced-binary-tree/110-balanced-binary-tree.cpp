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
    int helper(TreeNode* root)
    {
        if(root==nullptr)
            return 0;
        return 1+max(helper(root->left),helper(root->right));
    }
    
    bool isBalanced(TreeNode* root) {
        
        if(root==nullptr)
            return 1;
        
        int lh = helper(root->left);
        int rh = helper(root->right);

        return (abs(lh-rh)<=1) && isBalanced(root->left) && isBalanced(root->right);
        
    }
};