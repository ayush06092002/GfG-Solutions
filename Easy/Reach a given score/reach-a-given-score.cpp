//{ Driver Code Starts
// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    long long int solve(int i, int n, long long int target, const vector<int>& arr, vector<vector<long long int>>& dp)
    {
        if (i == n)
        {
            if (target == 0)
                return 1;
            return 0;
        }
        if (target < 0)
            return 0;
        
        if (dp[i][target] != -1)
            return dp[i][target];
    
        long long int waysIncludingCurrent = 0;
        if (arr[i] <= target)
        {
            waysIncludingCurrent = solve(i, n, target - arr[i], arr, dp);
        }
    
        long long int waysExcludingCurrent = solve(i + 1, n, target, arr, dp);
    
        dp[i][target] = waysIncludingCurrent + waysExcludingCurrent;
        return dp[i][target];
    }
    
    long long int count(long long int n)
    {   
        vector<int> arr = {3, 5, 10};
        vector<vector<long long int>> dp(arr.size(), vector<long long int>(n + 1, -1));
        return solve(0, arr.size(), n, arr, dp);
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		Solution obj;
		cout<<obj.count(n)<<endl;
	}
	return 0;
}
// } Driver Code Ends