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
    int sum = 0, deepest = 0;
public:
    void LeaveSum(TreeNode *root, int depth)
    {
        if(root == NULL)
            return;
        if(root -> left == NULL && root -> right == NULL)
        {
            if(depth == deepest)
                sum += root -> val;
            else if(depth > deepest)
            {
                sum = root -> val, deepest = depth;
            }
        }
        LeaveSum(root -> left, depth + 1);
        LeaveSum(root -> right, depth + 1);
    }
    int deepestLeavesSum(TreeNode* root) {
        int depth = 0;
        LeaveSum(root, depth);
        return sum;
    }
};