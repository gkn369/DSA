class Solution {
  public:
    int findCeil(Node* root, int x) {
        // code here
        int ceil = -1;
        if(root == NULL)
            return ceil;
            
        Node *node = root;
        
        while(node != NULL)
        {
            if(node -> data == x)
                return x;
            if(node -> data < x)
            {
                node = node -> right;
            }
            else
            {
                ceil = node -> data;
                node = node -> left;
            }
        }
        
        return ceil;
    }
};
