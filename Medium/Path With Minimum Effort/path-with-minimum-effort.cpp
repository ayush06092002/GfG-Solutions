//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<int>> eff(n, vector<int>(m, 1e9));
        eff[0][0] = 0;
        pq.push({0, {0, 0}});
        
        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        
        while(!pq.empty())
        {
            auto p = pq.top();
            int currE = p.first;
            int x = p.second.first;
            int y = p.second.second;
            pq.pop();
            
            for(auto pr : dir)
            {
                int X = x + pr.first;
                int Y = y + pr.second;
                
                if(X >= 0 && X < n && Y >= 0 && Y < m)
                {
                    int newE = max(currE, abs(heights[X][Y] - heights[x][y]));
                    
                    if(newE < eff[X][Y])
                    {
                        eff[X][Y] = newE;
                        pq.push({newE, {X, Y}});
                    }
                }
            }
        }
        return eff[n - 1][m - 1];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends