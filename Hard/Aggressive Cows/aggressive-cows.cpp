//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool isPossible(int mid, vector<int>& stalls, int n, int k)
    {
        int cows = 1;
        int lastCow = stalls[0];
        for(int i = 1; i < n; i++)
        {
            int pos = stalls[i] - lastCow;
            if(pos >= mid)
            {
                lastCow = stalls[i];
                cows++;
            }
            if(cows == k)
                return true;
        }
        
        return false;
    }

    int solve(int n, int k, vector<int> &stalls) {
    
        sort(stalls.begin(), stalls.end());
        int low = 1, high = stalls[n - 1] - stalls[0];
        int mid;
        while(low <= high)
        {
            mid = (low + high) >> 1;
            if(isPossible(mid, stalls, n, k))
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        
        return high;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends