//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int longestCommonSubsequence(string text1, string text2) {
        int l1 = text1.length(), l2 = text2.length();
        vector<int> prev(l2 + 1, 0);
        for(int i = 1; i <= l1; i++)
        {
            vector<int> curr(l2 + 1, 0);
            for(int j = 1; j <= l2; j++)
            {
                if(text1[i - 1] == text2[j - 1])
                {
                    curr[j] = 1 + prev[j - 1];
                }
                else
                {
                   curr[j] = max(curr[j - 1], prev[j]);
                }
            }
            prev = curr;
        }
        // return solve(l1 - 1, l2 - 1, text1, text2, dp);
        return prev[l2];
    }
    int kPalindrome(string str, int n, int k)
    {
        string rev = str;
        reverse(rev.begin(), rev.end());
        int diff = n - longestCommonSubsequence(str, rev);
        
        return (diff <= k) ? 1 : 0;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.kPalindrome(str, n, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends