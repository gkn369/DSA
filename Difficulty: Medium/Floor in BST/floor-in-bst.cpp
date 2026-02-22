/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    int floor(Node* root, int x) {
        // code here
        int floor = -1;
        
        Node *node = root;
        while(node != NULL)
        {
            if(node -> data == x)
                return x;
                
            if(node -> data < x)
            {
                floor = node -> data;
                node = node -> right;
            }
            else
            {
                node = node -> left;
            }
        }
        
        return floor;
    }
};