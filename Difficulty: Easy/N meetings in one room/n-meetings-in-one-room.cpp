class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        int n = start.size();
        
        if(n == 0)
            return 0;
        
        vector<pair<int, int>> meetings;
        
        for(int i = 0; i < n; i++)
        {
            meetings.push_back({start[i], end[i]});
        }
        
        sort(meetings.begin(), meetings.end(), [](pair<int, int>&a, pair<int, int> &b){
            return a.second < b.second;
        });
        
        int cnt = 1;
        int lastTime = meetings[0].second;
        for(int i = 1; i < n; i++)
        {
            if(meetings[i].first > lastTime)
            {
                cnt++;
                lastTime = meetings[i].second;
            }
        }
        
        return cnt;
    }
};