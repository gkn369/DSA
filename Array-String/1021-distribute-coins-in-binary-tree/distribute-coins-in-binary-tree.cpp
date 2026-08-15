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
    int moves = 0;
    int postorder(TreeNode *root){
        if(root == NULL)
            return 0;

        int lh = postorder(root -> left);
        int rh = postorder(root -> right);

        moves += abs(lh) + abs(rh);
        
        return root -> val + lh + rh - 1;

    }
    int distributeCoins(TreeNode* root) {
        postorder(root);
        return moves;
    }
};