//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int solve(int i, int prev, int n, vector<int> &a, vector<vector<int>> &dp){
        if(i >= n){
            return 0;
        }

        if(dp[i][prev + 1] != -1){ 
            return dp[i][prev + 1];
        }

        int take = INT_MIN;
        if(prev == -1 || abs(a[i] - a[prev]) == 1){
            take = 1 + solve(i + 1, i, n, a, dp);
        }
        int not_take = solve(i + 1, prev, n, a, dp);

        return dp[i][prev + 1] = max(take, not_take);
    }

    int longestSubseq(int n, vector<int> &a) {
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(0, -1, n, a, dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        vector<int> a(n);
        Array::input(a, n);

        Solution obj;
        int res = obj.longestSubseq(n, a);

        cout << res << endl;
    }
}

// } Driver Code Ends