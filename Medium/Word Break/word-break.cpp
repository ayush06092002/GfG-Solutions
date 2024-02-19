//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    int solve(int start, int n, string &A, vector<string> &B, vector<int> &dp)
    {
        if(start == n)
            return 1;
        
        if(dp[start] != -1)
            return dp[start];
        
        for(int end = start; end < n; end++)
        {
            string temp = A.substr(start, end - start + 1);
            if(find(B.begin(), B.end(), temp) != B.end())
            {
                if(solve(end + 1, n, A, B, dp))
                    return dp[start] = 1;
            }
        }
        
        return dp[start] = 0;
    }
    int wordBreak(string A, vector<string> &B) {
        vector<int> dp(A.size() + 1, -1);
        return solve(0, A.size(), A, B, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends