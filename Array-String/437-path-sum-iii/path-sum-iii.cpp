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
    void solver(TreeNode *root, long long targetSum)
    {
        if(!root)
            return;
        if(targetSum == root -> val)
            ans++;
        solver(root -> left, targetSum - root -> val);
        solver(root -> right, targetSum - root -> val);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root)
            return 0;
        solver(root, targetSum);
        pathSum(root -> left, targetSum);
        pathSum(root -> right, targetSum);
        return ans;
    }
};