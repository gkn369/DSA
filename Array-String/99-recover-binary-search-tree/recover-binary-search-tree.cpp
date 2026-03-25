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
    vector<int> elem;
    void inorder(TreeNode *root)
    {
        if(root == NULL)
            return;
        inorder(root -> left);
        elem.push_back(root -> val);
        inorder(root -> right);
    }
    void inorderTrav(TreeNode* root, int &start)
    {
        if(root == NULL)
            return;
        inorderTrav(root -> left, start);
        if(root -> val != elem[start])
        {
            root -> val = elem[start];
        }
        start++;
        inorderTrav(root -> right, start);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        sort(elem.begin(), elem.end());
        int start = 0;
        inorderTrav(root, start);
    }
};