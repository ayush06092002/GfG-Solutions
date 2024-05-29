//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int solve(int i, int prev, int arr[], int n, vector<vector<int>> &dp){
	    if(i == n){
	        return 0;
	    }
	    
	    if(dp[i][prev + 1] != -1){{
	        return dp[i][prev + 1];
	    }}
	    
	    int pick = -1e8;
	    if(prev == -1 || arr[i] > arr[prev]){
	        pick = arr[i] + solve(i + 1, i, arr, n, dp);
	    }
	    int not_pick = solve(i + 1, prev, arr, n, dp);
	    
	    return dp[i][prev + 1] = max(pick, not_pick);
	}
	int maxSumIS(int arr[], int n)  
	{  
	    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
	    return solve(0, -1, arr, n, dp);
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends