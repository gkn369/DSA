/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParent(TreeNode *root, unordered_map<TreeNode*, TreeNode*> &parent)
    {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            for(int i = 0; i < n; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if(node -> left)
                {
                    parent[node -> left] = node;
                    q.push(node -> left);
                }
                if(node -> right)
                {
                    parent[node -> right] = node;
                    q.push(node -> right);
                }
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;

        markParent(root, parent);
        unordered_map<TreeNode*,bool> visited;
        vector<int> ans;

        solve(target, k, parent, visited, ans);
        return ans;
    }
    void solve(TreeNode *target, int k, unordered_map<TreeNode*, TreeNode*> parent, unordered_map<TreeNode*,bool> visited, vector<int> &ans)
    {
        if(k == 0)
            ans.push_back(target -> val);

        visited[target] = true;

        if(target->left && !visited[target->left])
        {
            solve(target->left,k-1, parent,visited,ans);
        }
        if(target->right && !visited[target->right])
        {
            solve(target->right,k-1, parent,visited,ans);
        }
        if(parent[target]!=NULL && !visited[parent[target]])
        {
            solve(parent[target], k-1, parent,visited,ans);
        }
    }
    
};