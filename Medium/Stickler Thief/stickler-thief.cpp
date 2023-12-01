//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int solve(int arr[], int idx, vector<int> &dp)
    {
        if(idx < 0)
            return 0;
        
        if(idx == 0)
            return arr[0];
        
        if(dp[idx] != -1)
            return dp[idx];
        
        int take = arr[idx] + solve(arr, idx - 2, dp);
        int not_take = solve(arr, idx - 1, dp);
        
        return dp[idx] = max(take, not_take);
    }
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        vector<int> dp(n + 1, -1);
        // return solve(arr, n - 1, dp);
        
        dp[0] = arr[0];
        dp[1] = max(arr[0], arr[1]);
        
        for(int i = 2; i < n; i++)
        {
            int take = arr[i] + dp[i - 2];
            int not_take = dp[i - 1];
            
            dp[i] = max(take, not_take);
        }
        
        return dp[n - 1];
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends