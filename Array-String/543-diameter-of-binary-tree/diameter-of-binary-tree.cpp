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

    int findHeight(TreeNode *root, int &maxA)
    {
        if(root == NULL)
            return 0;

        int lh = findHeight(root -> left, maxA);
        int rh = findHeight(root -> right, maxA);

        maxA = max(maxA, lh + rh);
        return 1+max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxA = 0;

        if(root == NULL)
            return 0;
        
        findHeight(root, maxA);
    
        return maxA;
    }

    //T.C = O(N*N)
    // int maxA = INT_MIN;
    // int findHeight(TreeNode *root)
    // {
    //     if(root == NULL)
    //     return 0;

    //     int lh = findHeight(root -> left);
    //     int rh = findHeight(root -> right);
    //     maxA = max(lh + rh, maxA);
    //     return 1 + max(lh, rh);
    // }
    // int diameterOfBinaryTree(TreeNode* root) {
    //     if(root == NULL)
    //         return 0;
        
    //     int lh = findHeight(root -> left);
    //     int rh = findHeight(root -> right);
    //     maxA = max(lh + rh, maxA);
    //     return maxA;
    // }

    
};