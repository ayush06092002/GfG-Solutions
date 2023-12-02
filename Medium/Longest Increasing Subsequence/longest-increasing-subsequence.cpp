//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int solve(int arr[], int idx, int prev,  vector<vector<int>> &dp)
    {
        if(idx < 0)
            return 0;
        
        if(dp[idx][prev + 1] != -1)
            return dp[idx][prev + 1];
            
        int take = 0;
        
        if(prev == -1 || arr[idx] < arr[prev])
        {
            take = 1 + solve(arr, idx - 1, idx, dp);
        }
        
        int not_take = 0 + solve(arr, idx - 1, prev, dp);
        
        return dp[idx][prev + 1] = max(take, not_take);
    }
    
    int longestSubsequence(int n, int arr[])
    {
        //memoization
        // vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        // return solve(arr, n - 1, -1, dp);
        //tabulation
        
        // vector<int> dp(n, 1);
        
        // for(int i = 1; i < n; i++)
        // {
        //     for(int j = 0; j < i; j++)
        //     {
        //         if(arr[i] > arr[j])
        //         {
        //             dp[i] = max(dp[i], dp[j] + 1);
        //         }
        //     }
        // }
        
        // return *max_element(dp.begin(), dp.end());
        
        // both of these approaches gives tle
        
        vector<int> ans;
        
        for(int i = 0; i < n; i++)
        {
            auto it = lower_bound(ans.begin(), ans.end(), arr[i]);
            
            if(it == ans.end())
            {
                ans.push_back(arr[i]);
            }
            else
            {
                *it = arr[i];
            }
        }
        
        return ans.size();
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends