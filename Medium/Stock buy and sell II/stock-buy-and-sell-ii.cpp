//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int solve(int i, int flag, int n, vector<int> &prices, vector<vector<int>> &dp)
    {
        if(i == n)
            return 0;
        
        if(dp[i][flag] != -1)
            return dp[i][flag];
        
        if(flag)
        {
            int buy = solve(i + 1, false, n, prices, dp) - prices[i];
            int not_buy = solve(i + 1, true, n, prices, dp);
            
            return dp[i][flag] = max(buy, not_buy);
        }
        
        int sell = solve(i + 1, true, n, prices, dp) + prices[i];
        int not_sell = solve(i + 1, false, n, prices, dp);
        
        return dp[i][flag] = max(sell, not_sell);
    }
    
    int stockBuyAndSell(int n, vector<int> &prices) {
        if(n == 1)
            return 0;
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, true, n, prices, dp);    
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> prices(n);
        Array::input(prices,n);
        
        Solution obj;
        int res = obj.stockBuyAndSell(n, prices);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends