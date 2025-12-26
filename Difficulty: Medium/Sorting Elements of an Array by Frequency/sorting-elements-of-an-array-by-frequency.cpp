#include <iostream>
using namespace std;
bool comp(pair<int, int>a, pair<int, int>b)
{
    if(a.second == b.second)
    {
        return a.first < b.first;
    }
    return a.second > b.second;
}
int main() {
	//code here
	int t;
	cin >> t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    int arr[n];
	    map<int, int>mp;
	    for(int i = 0; i < n; i++)
	    {
	        cin >> arr[i];
	        mp[arr[i]]++;
	    }
	    vector<pair<int, int>>v;
	    for(auto it : mp)
	    {
	        v.push_back({it.first, it.second});
	    }
	    sort(v.begin(), v.end(), comp);
	    for(auto it : v)
	    {
	        while(it.second--)
	        {
	            cout << it.first << " ";
	        }
	    }
	    cout << endl;
	}
	
	return 0;
}