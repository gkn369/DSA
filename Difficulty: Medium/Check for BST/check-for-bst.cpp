/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    bool validBST(Node *root, int min, int max)
    {
        if(root == NULL)
            return true;
            
        if(root -> data <= min || root -> data >= max)
            return false;
            
        return validBST(root -> left, min, root -> data) && validBST(root -> right, root -> data, max);
        
    }
    bool isBST(Node* root) {
        // code here
        return validBST(root, INT_MIN, INT_MAX);
    }
};