//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pattern, string text)
        {
            vector<int> vec;
            
            int len = pattern.length();
            
            for(int i = 0; i + len <= text.length(); ++i)
            {
                if(text.substr(i, len) == pattern)
                {
                    vec.push_back(i + 1);
                }
            }
            
            return vec;
        }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends