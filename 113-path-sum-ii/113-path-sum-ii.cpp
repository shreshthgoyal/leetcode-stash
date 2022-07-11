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
    vector<vector<int>> paths;
    
    void helper(TreeNode* root, int k, vector<int> path)
    {
        path.push_back(root->val);

        if(!root->left && !root->right)
        {
            int sum = 0;
            for(auto &i:path)
                sum+=i;
            
            if(sum==k)
                paths.push_back(path);
            
            return;
        }
        

        if(root->left)
          { helper(root->left,k,path);}
        
        if(root->right)
           { helper(root->right,k,path);}
        
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root==nullptr)
            return paths;
        vector<int> path;
        helper(root, targetSum, path);
        return paths;
    }
};