//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int solve(int i, int val, vector<int> &coins, vector<vector<int>>& dp)
	{
	    if(i == 0)
	    {
	        if(val % coins[i] == 0)
	            return val / coins[i];
	        
	        return 1e9;
	    }
	    
	    if(dp[i][val] != -1)
	        return dp[i][val];
	       
	    int not_take = solve(i - 1, val, coins, dp);
	    int take = 1e9;
	    if(val >= coins[i])
	        take = 1 + solve(i, val - coins[i], coins, dp);
	   
	    return dp[i][val] = min(take, not_take);
	}
	
	int minCoins(vector<int> &coins, int M, int V) 
	{ 
	    vector<vector<int>> dp(M, vector<int>(V + 1, -1));
	    int ans = solve(M - 1, V, coins, dp);
	    return ans == 1e9 ? -1 : ans;
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        vector<int> coins(m);
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends