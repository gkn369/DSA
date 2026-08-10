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
    int height(TreeNode *root)
    {
        if(root == NULL)
            return 0;
        int lh = height(root -> left);
        int rh = height(root -> right);

        return 1 + max(lh, rh);
    }
    void fillString(TreeNode* root, vector<vector<string>>&ans, int row, int low, int high)
    {
        if(root == NULL)
            return;
        int mid = low + (high - low) / 2;
        ans[row][mid] = to_string(root -> val);
        fillString(root -> left, ans, row + 1, low, mid - 1);
        fillString(root -> right, ans, row + 1, mid + 1, high);
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int h = height(root);
        int m = h;
        int n = pow(2 , h) - 1;
        vector<vector<string>> ans(m, vector<string>(n, ""));
        fillString(root, ans, 0, 0, n-1);
        return ans;
    }
};