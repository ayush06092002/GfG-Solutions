//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
    int solve(vector<vector<int>>& points, int i, int j, int m, int n, vector<vector<int>> &dp) {
        if (i == m - 1 && j == n - 1) {
            return max(1, 1 - points[i][j]);
        }
        
        if (i == m || j == n) {
            return INT_MAX; 
        }
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int points_needed = min(solve(points, i + 1, j, m, n, dp),
                                solve(points, i, j + 1, m, n, dp));
        
        int min_points = max(1, points_needed - points[i][j]);
        
        return dp[i][j] = min_points;
    }
    
    int minPoints(int m, int n, vector<vector<int>>& points) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(points, 0, 0, m, n, dp);
    }
};


//{ Driver Code Starts.
int main() 
{
   
   	int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;

        vector<vector<int>> a(m, vector<int>(n));

        for(int i = 0; i < m; i++)
        	for(int j = 0; j < n; j++)
        		cin >> a[i][j];

        

	    Solution ob;
	    cout << ob.minPoints(m,n,a) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends