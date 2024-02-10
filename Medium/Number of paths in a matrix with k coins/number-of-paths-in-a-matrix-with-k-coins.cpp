//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    long long solve(int i, int j, int k, vector<vector<int>> &arr, vector<vector<vector<long long>>> &dp)
    {
        if(i < 0 || j < 0 || k < 0)
            return 0;
        if(i == 0 && j == 0)
        {
            if(k - arr[i][j] == 0)
                return 1;
            
            return 0;
        }
        if(dp[i][j][k] != -1)
            return dp[i][j][k];
        
        int up = solve(i - 1, j, k - arr[i][j], arr, dp);
        int left = solve(i, j - 1, k - arr[i][j], arr, dp);
        
        return dp[i][j][k] = up + left;
    }
    
    long long numberOfPath(int n, int k, vector<vector<int>> arr){
        
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n, vector<long long>(k + 1, -1)));
        return solve(n - 1, n - 1, k, arr, dp);
    }
};

//{ Driver Code Starts.

int main()
{
    Solution obj;
    int i,j,k,l,m,n,t;
    cin>>t;
    while(t--)
    {
        cin>>k>>n;
        vector<vector<int>> v(n+1, vector<int>(n+1, 0));
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin>>v[i][j];
        cout << obj.numberOfPath(n, k, v) << endl;
    }
}
// } Driver Code Ends