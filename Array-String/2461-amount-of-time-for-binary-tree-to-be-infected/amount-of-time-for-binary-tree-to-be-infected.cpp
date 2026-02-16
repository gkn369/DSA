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
    int findMaxDist(unordered_map<TreeNode*, TreeNode*> parent, TreeNode* target)
    {
        queue<TreeNode*>q;

        q.push(target);

        map<TreeNode*, int>vis;

        vis[target] = 1;

        int maxi = 0;

        while(!q.empty())
        {
            int sz = q.size();
            int count = 0;

            for(int i = 0; i < sz; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                if(node -> left && !vis[node -> left])
                {
                    count = 1;
                    q.push(node -> left);
                    vis[node -> left] = 1;
                }
                if(node -> right && !vis[node -> right])
                {
                    count = 1;
                    q.push(node -> right);
                    vis[node -> right] = 1;
                }
                if(parent[node] && !vis[parent[node]])
                {
                    count = 1;
                    q.push(parent[node]);
                    vis[parent[node]] = 1;
                }
            }
            if(count == 1)
                maxi++;
        }
        return maxi;
    }
    TreeNode* mark_parent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent, int start)
    {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode *res;
        while(!q.empty())
        {
            int n = q.size();
            
            for(int i = 0; i < n; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if(node -> val == start)
                    res = node;
                if(node -> left)
                {
                    q.push(node -> left);
                    parent[node -> left] = node; 
                }
                if(node -> right)
                {
                    q.push(node -> right);
                    parent[node -> right] = node;
                }
            }
        }
        return res;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parent;
        TreeNode* target = mark_parent(root, parent, start);

        return findMaxDist(parent, target);

    }
};