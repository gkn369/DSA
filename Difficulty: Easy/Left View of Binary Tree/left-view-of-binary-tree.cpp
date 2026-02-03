/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    void view(Node *root, vector<int> &ans, int level)
    {
        if(root == NULL)
            return;
            
        if(level == ans.size())
            ans.push_back(root -> data);
        if(root -> left)
            view(root -> left, ans, level + 1);
        if(root -> right)
            view(root -> right, ans, level + 1);
        
    }
    vector<int> leftView(Node *root) {
        // code here
        vector<int> ans;
        view(root, ans, 0);
        
        return ans;
    }
};