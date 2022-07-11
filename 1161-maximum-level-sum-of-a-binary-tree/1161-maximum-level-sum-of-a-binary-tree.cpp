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
    unordered_map<int, int> m;
    
    void f(TreeNode* root, int h)
    {
        if(root == nullptr)
            return;
        f(root->left, h+1);
        f(root->right, h+1);
        
        m[h]+=root->val;
    }
    
    int maxLevelSum(TreeNode* root) {
        
        if(root==NULL)
            return 0;
        
        f(root, 1);
        
        int ans = INT_MIN;
        int max_sum  = INT_MIN;
        
        for(auto &i:m)
        {
            if(i.second > max_sum)
            {
                ans = i.first;
                max_sum = i.second;
            }
                
        }
        
        return ans;
    }
};