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
    void pathsum(TreeNode *root, int targetSum, vector<vector<int>> &ans, vector<int> res)
    {
        if(root == NULL)
            return;
        res.push_back(root -> val);

        if(targetSum == root -> val && root -> left == NULL && root -> right == NULL)
        {
            ans.push_back(res);
        }

        pathsum(root -> left, targetSum - root -> val, ans, res);
        pathsum(root -> right, targetSum - root -> val, ans, res);

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> res;
        pathsum(root, targetSum, ans, res);

        return ans;
    }
};