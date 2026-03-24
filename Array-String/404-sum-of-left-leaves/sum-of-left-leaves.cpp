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
    void findsum(TreeNode *root, int &sum, bool flag)
    {
        if(root -> left == NULL && root -> right == NULL && flag == true)
            sum += root -> val;
        if(root -> left)
            findsum(root -> left, sum, true);
        if(root -> right)
            findsum(root -> right, sum, false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        if(root == NULL)
            return sum;
        bool flag = false;
        findsum(root, sum, flag);
        return sum;
    }
};