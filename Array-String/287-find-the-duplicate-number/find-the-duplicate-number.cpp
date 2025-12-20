class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        int i = 0;
        while (true) {  // Traverse arr[ele] and mark the respective visited indices as -ve
        // Now if you find an ele as marked -ve then return the index
        i = abs(arr[i]);
        if (arr[i] < 0) {
            return i;
        }
        arr[i] = -1 * arr[i];  // Else keep on traversing until you find one
        }
    }
};