//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    long long int solve(int i,int j, int arr[], vector<vector<int>> &dp){
        if(i > j){
            return 0;
        }
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int take = min(solve(i + 2, j, arr, dp), solve(i + 1, j - 1, arr, dp)) + arr[i];
        int not_take= min(solve(i, j - 2, arr, dp), solve(i + 1, j - 1, arr, dp)) + arr[j];

        return dp[i][j] = max(take,not_take);
        
    }
    long long maximumAmount(int n, int arr[]){
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, n-1, arr, dp);
    }
};

//{ Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(n,a)<<endl;
	}
	return 0;
}
// } Driver Code Ends