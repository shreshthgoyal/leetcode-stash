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
    vector<int> rightSideView(TreeNode* root) {
    
    vector<int> ans;

    if (root == NULL)
        return ans;
        
    queue<TreeNode*> q;
    q.push(root);
        q.push(nullptr);
 TreeNode* curr;
    while (q.empty() == false) {
        
        
        if(q.front() == nullptr) {
            ans.push_back(curr->val);
            q.pop();
            if(!q.empty())
            q.push(nullptr);
        }
        
       else 
       { curr = q.front();
        
 
        if (curr->left)
            q.push(curr->left);
 
        if (curr->right)
            q.push(curr->right);
               q.pop();
}
        
    }
        
        return ans;
    }
};