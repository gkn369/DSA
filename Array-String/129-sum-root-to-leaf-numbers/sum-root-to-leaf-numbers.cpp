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
    void getSum(TreeNode* root, int &sum, string s)
    {
        if(root == NULL)
            return;
        s += to_string(root -> val);
        if(root -> left == NULL && root -> right == NULL)
        {
            sum += stoi(s);
        }

        if(root -> left)
            getSum(root -> left, sum, s);
        if(root -> right)
            getSum(root -> right, sum, s);

    }
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        string s;
        getSum(root, sum, s);
        return sum;
    }
};