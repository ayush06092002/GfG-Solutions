//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> antiDiagonalPattern(vector<vector<int>> m) 
    {
        int n = m.size();
        
        vector<vector<int>> dp(2*n-1);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dp[i+j].push_back(m[i][j]);
            }
        }
        
        vector<int> ans;
        int x = (2*n -1);
        for(int i=0;i<x;i++){
            for(int j=0;j<dp[i].size();j++){
                ans.push_back(dp[i][j]);
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix;
        matrix.resize(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> ans = ob.antiDiagonalPattern(matrix);
        for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends