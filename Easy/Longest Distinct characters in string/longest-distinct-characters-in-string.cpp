//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int longestSubstrDistinctChars (string s)
{
    vector<int> charMap(128, -1);
    int n = s.length();
    int start = 0, end = 0;
    int maxLength = 0;
    while(end < n){
        char ch = s[end];
        if(charMap[ch] == -1 || charMap[ch] < start){
            charMap[ch] = end;
            maxLength = max(maxLength, end - start + 1);
            end++;
        }
        else{
            start = charMap[ch] + 1;
        }
    }
    
    return maxLength;
}