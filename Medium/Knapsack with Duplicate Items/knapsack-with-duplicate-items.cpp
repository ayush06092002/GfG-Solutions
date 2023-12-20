//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int i, int weight, int w[], int v[], vector<vector<int>> &dp)
    {
        if (weight == 0)
            return 0;
    
        if (i == 0)
        {
            if (w[i] <= weight)
                return (weight / w[i]) * v[i];
            else
                return 0;
        }
    
    	if(dp[i][weight] != -1)
    		return dp[i][weight];
    	
    	int not_take = solve(i - 1, weight, w, v, dp);
    	int take = 0;
    	if(w[i] <= weight)
    		take = v[i] + solve(i, weight - w[i], w, v, dp);
    
    	return dp[i][weight] = max(not_take, take);
    	
    }
    
    int knapSack(int n, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));
        return solve(n - 1, W, wt, val, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends