//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    vector<vector<int>> dp;
    Solution()
    {
        dp = vector<vector<int>>(100, vector<int>(10000, -1));
    }
    
    int solve(vector<int> &arr, int target, int idx)
    {
        if(target == 0)
            return 1;
        
        if(idx < 0 || target < 0)
            return 0;
        
        if(idx == 0 && target == arr[0])
            return 1;
        
        if(dp[idx][target] != -1)
        {
            return dp[idx][target];
        }
        
        int not_take = solve(arr, target, idx - 1);
        int take = false;
        if(target - arr[idx] >= 0)
        {
            take = solve(arr, target - arr[idx], idx - 1);
        }
        
        return dp[idx][target] = (take || not_take);
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here
        return solve(arr, sum, arr.size() - 1);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends