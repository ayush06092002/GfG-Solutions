//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int calc(int num, int n, int m)
	{
	    long long val = 1;
	    for(int i = 0; i < n; i++)
	    {
	        val *= num;
	        if(val > m)
	            return 2;
	    }
	    if(val == m)
	        return 1;
	    
	    return 0;
	}
	int NthRoot(int n, int m)
	{
	    int low = 1, high = m;
	    while(low <= high)
	    {
	        int mid = low + (high - low) / 2;
	        int val = calc(mid, n, m);
	        if(val == 1)
	            return mid;
	        
	        else if(val == 0)
	            low = mid + 1;
	        
	        else
	            high = mid - 1;
	    }
	    
	    
	    return -1;
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends