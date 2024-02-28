//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int DivisibleByEight(string s) {
        int n = s.size();
        int sum = 0;

        if (n < 3) {
            int num = stoi(s);
            if (num % 8 == 0)
                return 1;
            else
                return -1;
        }

        if (n >= 3) {
            if (s[n - 1] == '0' && s[n - 2] == '0' && s[n - 3] == '0')
                return 1;
            int num = (s[n - 1] - '0') + (s[n - 2] - '0') * 10 + (s[n - 3] - '0') * 100;
            if (num % 8 == 0)
                return 1;
        }
        
        return -1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.DivisibleByEight(S)<<"\n";
    }
}
// } Driver Code Ends