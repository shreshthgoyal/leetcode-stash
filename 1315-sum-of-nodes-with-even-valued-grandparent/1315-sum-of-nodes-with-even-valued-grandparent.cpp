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
    int ans = 0;
    
    void helper(TreeNode* curr, TreeNode* parent, TreeNode* grandparent)
    {
        if(curr==nullptr)
            return;
    
        
        if(grandparent && !(grandparent->val%2))
        {
            ans+=curr->val;
        }
        
        helper(curr->left, curr, parent);
        helper(curr->right, curr, parent);
    }
    
    int sumEvenGrandparent(TreeNode* root) {
        helper(root,nullptr,nullptr);
        return ans;
    }
};