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
    int maxSum(TreeNode* root, int &maxA)
    {
        if(root == NULL)
            return 0;
        
        int lh = max(0, maxSum(root -> left, maxA));
        int rh = max(0, maxSum(root -> right, maxA));

        maxA = max(maxA, root -> val + lh + rh);

        return root -> val + max(lh, rh);
    }
    int maxPathSum(TreeNode* root) {
        int maxA = INT_MIN;
        maxSum(root, maxA);
        return maxA;
    }
};