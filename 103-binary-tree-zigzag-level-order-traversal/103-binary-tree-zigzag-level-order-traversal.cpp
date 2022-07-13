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
    vector<vector<int>> ans;
    
    void zigzag(TreeNode* root)
    {
     if(root==NULL)
         return;
    queue<TreeNode*> q;
        q.push(root);
        int dir = 0;
        while(!q.empty())
        {
            int sz = q.size();
            vector<int> row;
            while(sz--)
            {
            TreeNode* node = q.front();
            row.push_back(node->val);
            q.pop();
            

                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            if(dir%2==1)
                reverse(row.begin(), row.end());
            ans.push_back(row);
            row.clear();
            dir++;
        }
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        zigzag(root);
        return ans;
    }
};