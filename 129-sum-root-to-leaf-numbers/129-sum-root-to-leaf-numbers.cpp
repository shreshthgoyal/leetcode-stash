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
    
    void helper(TreeNode* root, int curr_sum, int& ans)
    {
        if(!root->left && !root->right)
        {
            ans+= curr_sum;
            //cout << curr_sum << " ";
            return;
        }
        
        if(root->left)
        {
            helper(root->left, curr_sum*10 + root->left->val, ans);
        }
        
        if(root->right)
        {
            helper(root->right, curr_sum*10 + root->right->val, ans);
        }
        
    }
    
    int sumNumbers(TreeNode* root) {
        if(root==nullptr)
            return 0;
        
        int ans = 0;

        helper(root, root->val, ans);

        
        return ans;
    }
};