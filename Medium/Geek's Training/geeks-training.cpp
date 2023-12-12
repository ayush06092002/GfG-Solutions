//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int solve(vector<vector<int>>& points, int idx, int prev, vector<vector<int>> &dp)
    {
        if(dp[idx][prev] != -1)
            return dp[idx][prev];
            
        if(idx == 0)
        {
            int maxi = -1;
            for(int i = 0; i < 3; i++)
            {
                if(i != prev)
                    maxi = max(maxi, points[0][i]);
            }
            
            return maxi;
        }
        
        int maxi = 0;
        
        for(int i = 0; i < 3; i++)
        {
            if(i == prev)
                continue;
            
            int sum = points[idx][i] + solve(points, idx - 1, i, dp);
            
            maxi = max(maxi, sum);
        }
        
        return dp[idx][prev] = maxi;
    }
    
    int maximumPoints(vector<vector<int>>& points, int n) {
        vector<vector<int>> dp(n + 1, vector<int>(4, -1));
        return solve(points, n - 1, 3, dp); //3 to make sure you try out all the possibilities at once for the 1st
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends