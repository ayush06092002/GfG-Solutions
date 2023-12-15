//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int i, int j, int n, int m, vector<vector<int>> &arr, vector<vector<int>> &dp)
    {
         
        if(i == n - 1)
            return arr[i][j];
    
        if(dp[i][j] != -1)
            return dp[i][j];
    
        int down = arr[i][j] + solve(i + 1, j, n, m, arr, dp);
    
        int leftDia = INT_MIN;
        if(j - 1 >= 0)
            leftDia = arr[i][j] + solve(i + 1, j - 1, n, m, arr, dp);
        
        int rightDia = INT_MIN;
        if(j + 1 < m)
            rightDia = arr[i][j] + solve(i + 1, j + 1, n, m, arr, dp);
    
        return dp[i][j] = max(down, max(leftDia, rightDia));
    }
    int maximumPath(int n, vector<vector<int>> &arr)
    {
        int m = n;
        int ans = -1e9;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        // for(int i = 0; i < m; i++)
        // {
        //     ans = max(ans, solve(0, i, n, m, matrix, dp));
        // }
        
        for(int i = 0; i < m; i++)
        {
            dp[n - 1][i] = arr[n - 1][i];
        }
        
        for(int row = n - 2; row >= 0; row--)
        {
            for(int col = 0; col < m; col++)
            {
                int down = arr[row][col] + dp[row + 1][col];
                int leftDia = INT_MIN;
                int rightDia = INT_MIN;
                
                if(col - 1 >= 0)
                    leftDia = arr[row][col] + dp[row + 1][col - 1];
                
                if(col + 1 < m)
                    rightDia = arr[row][col] + dp[row + 1][col + 1];
                    
                dp[row][col] = max(down, max(leftDia, rightDia));
            }
        }
        
        for(int i = 0; i < m; i++)
        {
            ans = max(ans, dp[0][i]);
        }
    
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends