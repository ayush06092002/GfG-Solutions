//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &matrix, int R, int C){
        int low = 1e9, high = -1e9;
        for(int i = 0; i < R; i++)
        {
            low = min(low, matrix[i][0]);
            high = max(high, matrix[i][C - 1]);
        }
        int count = 0, mid = 0, midIdx = (R * C) / 2;
        while(low <= high)
        {
            count = 0;
            mid = low + (high - low) / 2;
            for(int i = 0; i < R; i++)
            {
                count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
            
            if(count > midIdx)
                high = mid - 1;
            else
                low = mid + 1;
            
        }
        
        return low;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends