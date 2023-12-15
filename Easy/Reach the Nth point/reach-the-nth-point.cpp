//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    int solve(int i, vector<int> &dp)
	    {
	        if(i == 0)
	            return 1;
	        
	        if(i == 1)
	            return 1;
	       
	        if(dp[i] != -1)
	            return dp[i];
	        
	        return dp[i] = (solve(i - 1, dp) + solve(i - 2, dp)) % (int)(1e9 + 7);
	    }
		int nthPoint(int n){
		    vector<int> dp(n + 1, -1);
		    
		    return solve(n, dp);
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthPoint(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends