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
    vector<int> nodes;
    void inorder(TreeNode * root){
        if(root == NULL)
            return;
        inorder(root -> left);
        nodes.push_back(root -> val);
        inorder(root -> right);
    }
    TreeNode *build(int start, int end){
        if(start > end)
            return NULL;
        int mid = (start + end) / 2;

        TreeNode * curr = new TreeNode(nodes[mid]);

        curr -> left = build(start, mid - 1);
        curr -> right = build(mid + 1, end); 
        return curr;
    }
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        int n = nodes.size();
        int start = 0, end = n - 1;

        return build(start, end);
    }
};