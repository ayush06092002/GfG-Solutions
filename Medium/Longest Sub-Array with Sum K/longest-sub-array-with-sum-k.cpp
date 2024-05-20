//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        long long sum = 0;
        unordered_map<int, int> mp;
        int maxLength = 0;
        for(int i = 0; i < N; i++){
            sum += A[i];
            if(sum == K){
                maxLength = i + 1;
            }
            else if(mp.find(sum - K) != mp.end()){
                maxLength = max(maxLength, i - mp[sum - K]);
            }
            if(mp.find(sum) == mp.end()){
                mp[sum] = i;
            }
        }
        
        return maxLength;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends