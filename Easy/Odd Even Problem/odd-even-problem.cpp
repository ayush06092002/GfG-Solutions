//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string oddEven(string s) {
        vector<int> count(27, 0);
        int n = s.size();
        for(int i = 0; i < n; i++){
            count[s[i] - 'a' + 1]++;
        }
        
        int sum = 0;
        for (int i = 1; i <= 26; i++) {
            if (count[i] != 0) { 
                if (i % 2 == 0 && count[i] % 2 == 0) {
                    sum++;
                } else if (i % 2 != 0 && count[i] % 2 != 0) {
                    sum++;
                }
            }
        }
        return (sum % 2 == 0) ? "EVEN" : "ODD";
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s;
        getline(cin, s);

        Solution obj;
        string res = obj.oddEven(s);

        cout << res << "\n";
    }
}

// } Driver Code Ends