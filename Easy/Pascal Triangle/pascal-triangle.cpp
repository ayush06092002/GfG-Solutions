//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// #define ll long long
class Solution {
public:
    const int MOD = 1000000007;
    vector<long long> nthRowOfPascalTriangle(int n) {
        // code here
        vector<vector<long long>> res;
        res.push_back({1});
        if (n == 1) {
            return {1};
        }

        for (int i = 1; i < n; ++i) {
            vector<long long> temp;
            for (int k = 0; k <= i; ++k) {
                if (k == 0 || k == i) {
                    temp.push_back(1);
                } else {
                    temp.push_back((res[i - 1][k - 1] + res[i - 1][k]) % MOD);
                }
            }
            res.push_back(temp);
        }

        vector<long long> ans(res[res.size() - 1].begin(), res[res.size() - 1].end());
        return ans;
    }
};




//{ Driver Code Starts.


void printAns(vector<long long> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends