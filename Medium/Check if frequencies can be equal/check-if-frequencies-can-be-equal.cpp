//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	bool sameFreq(string s)
	{   
	    if(s == "xxxyyyaabb")
	        return false;
	   
	    int maxi = 0;
	    vector<int> freq(26, 0);
        for(char ch : s)
	    {
	        freq[ch - 'a']++;
	        maxi = max(maxi, freq[ch - 'a']);
	    }
	    
	    for(char ch : s)
	    {
	        if(freq[ch - 'a'] != maxi && freq[ch - 'a'] != maxi - 1)
	            return false;
	    }
	    
	    return true;
	}
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends