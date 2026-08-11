/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> mp;
        int sum = 0;

        for(auto it : employees){
            mp[it -> id] = it;
        }

        queue<Employee*> q;
        q.push(mp[id]);
        while(!q.empty())
        {
            auto elem = q.front();
            sum += elem -> importance;
            vector<int> sub = elem -> subordinates;
            for(auto x : sub)
            {
                q.push(mp[x]);
            }
            q.pop();
        }
        return sum;
    }
};