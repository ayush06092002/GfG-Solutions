//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int solve(int i, int weight, int w[], int v[], vector<vector<int>> &dp)
    {
        if (weight == 0)
            return 0;
    
        if (i == 0)
        {
            if (w[i] <= weight)
                return v[i];
            else
                return 0;
        }
    
    	if(dp[i][weight] != -1)
    		return dp[i][weight];
    	
    	int not_take = solve(i - 1, weight, w, v, dp);
    	int take = 0;
    	if(w[i] <= weight)
    		take = v[i] + solve(i - 1, weight - w[i], w, v, dp);
    
    	return dp[i][weight] = max(not_take, take);
    	
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
    	vector<vector<int>> dp(n, vector<int>(W + 1, 0));
    // 	return solve(n - 1, W, wt, val, dp);
        
        for(int i = 0; i <= W; i++)
        {
            if(wt[0] <= i)
                dp[0][i] = val[0];            
        }

        
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j <= W; j++)
            {
                int not_take = dp[i - 1][j];
                int take = 0;
                if(wt[i] <= j)
                    take = val[i] + dp[i - 1][j - wt[i]];
                
                dp[i][j] = max(take, not_take);
            }
        }
        
        return dp[n - 1][W];
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends