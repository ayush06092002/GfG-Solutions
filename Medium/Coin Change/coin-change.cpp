//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long solve(int coins[],vector<vector<long long>> &dp, int idx, int target)
    {
        if(target == 0)
            return dp[idx][target] = 1;
        
        if(idx == 0 || target < 0)
            return 0;
        
        if(dp[idx][target] != -1)
        {
            return dp[idx][target];
        }
        
        return dp[idx][target] = 
        solve(coins, dp, idx, target - coins[idx - 1]) + solve(coins, dp, idx - 1, target);
    }
    
    long long int count(int coins[], int n, int sum) {

        // code here.
        vector<vector<long long>> dp(n + 1, vector<long long>(sum + 1, 0));
        // return solve(coins, dp, n, sum);
        // for(int i = 0; i < n; i++)
        // {
        //     dp[i][0] = 1;
        // }
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j <= sum; j++)
            {
                dp[i][j] += dp[i - 1][j];
                
                if(j - coins[i - 1] >= 0)
                {
                    dp[i][j] += dp[i][j - coins[i - 1]];
                }
            }
        }
        return dp[n][sum];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends