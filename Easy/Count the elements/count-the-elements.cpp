//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> countElements(vector<int> &a, vector<int> &b, int n, vector<int> &query,
                              int q) {
        vector<int> mapB(100010, 0);
        for(int i = 0; i < n; i++)
        {
            mapB[b[i]]++;
        }
        
        // vector<int> prevFreqSum(100010);
        // prevFreqSum[0] = mapB[0];
        
        for(int i = 1; i < 100010; i++){
            mapB[i] = mapB[i - 1] + mapB[i];
        }
        
        vector<int> result;
        for(int i = 0; i < q; i++){
            result.push_back(mapB[a[query[i]]]);
        }
        
        return result;
    }
};


//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {

        int n;
        cin >> n;
        vector<int> a, b, ans;
        int input;
        for (int i = 0; i < n; i++) {
            cin >> input;
            a.push_back(input);
        }
        for (int i = 0; i < n; i++) {
            cin >> input;
            b.push_back(input);
        }
        int q;
        cin >> q;
        vector<int> query;
        for (int i = 0; i < q; i++) {
            cin >> input;
            query.push_back(input);
        }
        Solution obj;
        ans = obj.countElements(a, b, n, query, q);
        for (int i = 0; i < q; i++) {
            cout << ans[i] << endl;
        }
    }
    return 0;
}
// } Driver Code Ends