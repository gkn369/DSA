/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // code here
        
        Node *slow = head;
        Node *fast = head;
        
        while(fast != NULL && fast -> next != NULL)
        {
            fast = fast -> next -> next;
            slow = slow -> next;
            if(slow == fast)
                break;
        }
        
        if(fast==NULL || fast->next==NULL)
        {
            return 0;
        }
        int count = 1;
        
        slow = slow -> next;
        
        while(slow != fast)
        {
            slow = slow -> next;
            count++;
        }
        
        return count;
    }
};