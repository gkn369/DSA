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
    void solve(TreeNode *root, int val, int depth, int height)
    {
        if(root == NULL)
            return;

        if(depth - 1 == height)
        {
            TreeNode *nextLeftNode = root -> left;
            TreeNode *nextRightNode = root -> right;

            TreeNode *newLeftNode = new TreeNode(val);
            TreeNode *newRightNode = new TreeNode(val);
            root -> left = newLeftNode;
            root -> right = newRightNode;
            newLeftNode -> left = nextLeftNode;
            newRightNode -> right = nextRightNode;

            return;
        }

        solve(root -> left, val, depth, height + 1);
        solve(root -> right, val, depth, height + 1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(root == NULL)
            return NULL;
        int height = 1;
        if(depth == 1)
        {
            TreeNode *node = new TreeNode(val);
            node -> left = root;
            return node;
        }

        solve(root, val, depth, height);

        return root;
    }
};