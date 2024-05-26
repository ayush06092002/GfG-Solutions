//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int fun(string &s1,string &s2,int c1,int c2,int i,int j, vector<vector<int>> &dp)
    {
        if(i==s1.length() && j==s2.length())
        {
            return 0;
        }
        if(i==s1.length() && j!=s2.length())
        {
            return (s2.length()-j)*c2;
        }
        if(i!=s1.length() && j==s2.length())
        {
            return (s1.length()-i)*c1;
        }
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int cost=0;
        if(s1[i]==s2[j])
            cost=fun(s1,s2,c1,c2,i+1,j+1,dp);
        else 
            cost=min(c1+fun(s1,s2,c1,c2,i+1,j,dp),c2+fun(s1,s2,c1,c2,i,j+1,dp));
        
        return dp[i][j]=cost;
    }
    int findMinCost(string X, string Y, int costX, int costY) {
        int n = X.size();
        int m = Y.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(X[i-1]==Y[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        int c1=(n-dp[n][m])*costX;
        int c2=(m-dp[n][m])*costY;
        return c1+c2;
        // return fun(x, y, costX, costY, 0, 0, dp);
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;

        int costX, costY;
        cin >> costX >> costY;

        Solution ob;
        cout << ob.findMinCost(x, y, costX, costY);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends