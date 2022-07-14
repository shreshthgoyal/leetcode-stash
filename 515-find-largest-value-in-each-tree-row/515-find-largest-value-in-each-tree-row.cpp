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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(root==nullptr)
            return ans;
        queue<TreeNode*> q;
        q.push(root);

        vector<int> k;

        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                TreeNode* node = q.front();
                q.pop();
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
                
                int j = node->val;
                k.push_back(j);            
            }
            
            ans.push_back(*max_element(k.begin(),k.end()));
            k.clear();
        }        
        return ans;
    }
};