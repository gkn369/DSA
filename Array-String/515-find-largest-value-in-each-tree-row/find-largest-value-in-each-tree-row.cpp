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
//     vector<int> largestValues(TreeNode* root) {
//         vector<int> ans;
//         queue<TreeNode*> q;

//         q.push(root);

//         while(!q.empty())
//         {
//             int n = q.size();
//             int elem = INT_MIN;
//             for(int i = 0; i < n; i++)
//             {
//                 TreeNode *curr = q.front();
//                 q.pop();
//                 elem = max(elem, curr -> val);
//                 if(curr -> left)
//                     q.push(curr -> left);
//                 if(curr -> right)
//                     q.push(curr -> right);
//             }
//             ans.push_back(elem);
//         }
//         return ans;
//     }

    void dfs(TreeNode *root, int level, vector<int> &ans)
    {
        if(!root)
            return;

        if(level == ans.size())
        {
            ans.push_back(root -> val);
        }
        else
        {
            ans[level] = max(ans[level], root -> val);
        }

        dfs(root -> left, level + 1, ans);
        dfs(root -> right, level + 1, ans);
    }
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;

        dfs(root, 0, ans);

        return ans;
    }
};