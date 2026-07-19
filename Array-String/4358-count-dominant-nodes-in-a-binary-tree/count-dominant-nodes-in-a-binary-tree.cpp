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
    int count(TreeNode *root, int &dominant){
        if(root == NULL)
            return INT_MIN;
        int lh = count(root -> left, dominant);
        int rh = count(root -> right, dominant);

        int currSubMax = max({root -> val, lh, rh});

        if(root -> val == currSubMax)
            dominant++;
        
        return currSubMax;
    }
    int countDominantNodes(TreeNode* root) {
        int dominant = 0;
        count(root, dominant);
        return dominant;
    }
};