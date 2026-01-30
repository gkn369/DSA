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
    int count = 0;
    int solve(TreeNode* root, int maxA)
    {
        if(root == NULL)
        {
            return 0;
        }
        
        if(root -> val >= maxA)
            count++;

        maxA = max(maxA, root -> val);

        solve(root -> left, maxA);
        solve(root -> right, maxA);
        return count;
    }
    int goodNodes(TreeNode* root) 
    {
        return solve(root, root -> val);

    }
};