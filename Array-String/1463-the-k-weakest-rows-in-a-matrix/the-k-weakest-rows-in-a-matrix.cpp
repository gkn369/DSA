class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> rows;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int n = mat.size();
        int m = mat[0].size();

        for(int i = 0; i < n; i++)
        {
            int count = 0;
            for(int j = 0; j < m; j++)
            {
                if(mat[i][j] == 1)
                    count++;
            }
            pq.push({count, i});
        }

        while(k > 0)
        {
            auto temp = pq.top();
            pq.pop();

            rows.push_back(temp.second);
            k--;
        }
        return rows;
    }
};