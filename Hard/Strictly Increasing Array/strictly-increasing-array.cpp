//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
     int solve(int i, int prev, vector<int> &nums, vector<vector<int>> &dp)
    {
        if(i < 0)
            return 0;

        if(dp[i][prev] != -1)
            return dp[i][prev];
        
        int take = -1e8;
        if(prev == nums.size() || (nums[i] < nums[prev] && (nums[prev] - nums[i]) >= (prev - i)))
            take = 1 + solve(i - 1, i, nums, dp);
        
        int not_take = solve(i - 1, prev, nums, dp);

        return dp[i][prev] = max(take, not_take);
    }

    int min_operations(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return n - solve(n - 1, n, nums, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        Solution ob;
        int ans = ob.min_operations(nums);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends