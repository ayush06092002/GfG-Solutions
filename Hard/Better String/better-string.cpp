//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countDistinctSubsequences(string str) {
        int n = str.length();
        const int MOD = 1e9 + 7;
        
        vector<int> dp(n + 1, 0);
        
        vector<int> last(256, -1);
        
        dp[0] = 1;
        
        for (int i = 1; i <= n; ++i) {
            dp[i] = (2 * dp[i - 1]) % MOD;
            
            if (last[str[i - 1]] != -1) {
                dp[i] = (dp[i] - dp[last[str[i - 1]]] + MOD) % MOD;
            }
            
            last[str[i - 1]] = i - 1;
        }
        
        return dp[n];
}
    string betterString(string str1, string str2) {
        // code here
        int count1 = countDistinctSubsequences(str1);
        int count2 = countDistinctSubsequences(str2);
        
        if (count1 >= count2) {
            return str1;
        } else {
            return str2;
    }        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str1, str2;
        cin >> str1 >> str2;
        Solution obj;
        string ans = obj.betterString(str1, str2);
        cout << ans << "\n";
    }
}

// } Driver Code Ends