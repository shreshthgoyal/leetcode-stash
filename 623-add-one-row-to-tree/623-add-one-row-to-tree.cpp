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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(root==NULL)
            return root;
        
        if(depth==1)
        {
            TreeNode* head = new TreeNode();
            
            head->val = val;
            head->left = root;
            
            return head;
        }
        
        if(depth==2)
        {
            TreeNode* lt = new TreeNode(val, root->left, NULL);
            TreeNode* rt = new TreeNode(val, NULL, root->right);
            
            root->left = lt;
            root->right = rt;
            
            return root;
        }
        
        addOneRow(root->left, val, depth-1);
        addOneRow(root->right, val, depth-1);
        
        return root;
    }
};