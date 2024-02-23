//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
        //User function Template for C++
        // int solve(int i, int flag_buy, int cap, int n, vector<int> &price, vector<vector<vector<int>>> &dp)
        // {
        //     if(i == n || cap == 0)
        //     {
        //         return 0;
        //     }
            
        //     if(dp[i][flag_buy][cap] != -1)
        //         return dp[i][flag_buy][cap]; 
            
        //     if(flag_buy == 1)
        //     {
        //         int buy = solve(i + 1, 0, cap, n, price, dp) - price[i];
        //         int not_buy = solve(i + 1, 1, cap, n, price, dp);
                
        //         return dp[i][flag_buy][cap] = max(buy, not_buy);
        //     }
            
        //     int sell = solve(i + 1, 1, cap - 1, n, price, dp) + price[i];
        //     int not_sell = solve(i + 1, 0, cap, n, price, dp);
            
        //     return dp[i][flag_buy][cap] = max(sell, not_sell);
        // }
        int maxProfit(vector<int>&price){
            int n = price.size();
            vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
            for(int i = n - 1; i >= 0; i--)
            {
                for(int j = 0; j <= 1; j++)
                {
                    for(int k = 1; k <= 2; k++)
                    {
                        if(j == 0)
                        {
                            dp[i][j][k] = max(dp[i + 1][1][k - 1] + price[i], dp[i + 1][0][k]);
                        }
                        else
                        {
                            dp[i][j][k] = max(dp[i + 1][0][k] - price[i], dp[i + 1][1][k]);
                        }
                    }
                }
            }
    
            return dp[0][1][2];
        }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        Solution obj;
        cout<<obj.maxProfit(price)<<endl;
    }

}

// } Driver Code Ends