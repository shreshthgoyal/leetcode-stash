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
    
    vector<int> helper(TreeNode* root, int k)
    {
        if(root == nullptr)
            return {};
        
        if(!root->left && !root->right)
            return {1};
        
        vector<int> l = helper(root->left, k);       
        vector<int> r = helper(root->right, k);

        for(auto &i:l)
            for(auto &j:r)
                if(i+j<=k)
                    ans++;
        
        vector<int> v;
        
        for(auto &i:l)
            v.push_back(i+1);
        
        for(auto &j:r)
            v.push_back(j+1);
        
        return v;            
    }
    
    int countPairs(TreeNode* root, int distance) {
        helper(root, distance);
        return ans;
    }
};