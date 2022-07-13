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
    int height(TreeNode* root){
        if(root==NULL)
            return 0;
        
        return 1+max(height(root->left),height(root->right));
    }
    
    void bfs(TreeNode* root, vector<vector<int>> &ans, int h)
    {
        if(!root) return;
        
        ans[h].push_back(root->val);
        
        bfs(root->left, ans, h+1);
        bfs(root->right, ans, h+1);
        
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans(height(root));
        bfs(root, ans, 0);
        return ans;
    }
};