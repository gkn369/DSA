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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return buildTree(nums, 0, nums.size());
    }
    int findMaxIndex(vector<int> &nums, int start, int end){
        int maxInd = start;

        for(int i = start; i < end; i++)
        {
            if(nums[i] > nums[maxInd])
            {
                maxInd = i;
            }
        }
        return maxInd;
    }
    TreeNode* buildTree(vector<int>& nums, int start, int end)
    {
        if(start > end - 1)
            return NULL;
        int maxIndex = findMaxIndex(nums, start, end);

        TreeNode *root = new TreeNode(nums[maxIndex]);

        root -> left = buildTree(nums, start, maxIndex);
        root -> right = buildTree(nums, maxIndex + 1, end);

        return root;
    }
};