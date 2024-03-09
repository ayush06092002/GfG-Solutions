//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	string removeDuplicates(string str) {
	    string ans;
        vector<int> found(53, 0);
        for(char ch : str)
        {
            if(isupper(ch))
            {
                if(!found[ch - 'A' + 26])
                {
                    found[ch - 'A' + 26] = 1;
                    ans += ch;
                }                
            }
            else
            {
                if(!found[ch - 'a'])
                {
                    found[ch - 'a'] = 1;
                    ans += ch;
                }   
            }
        }
        
        return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        auto ans = ob.removeDuplicates(str);

        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends