//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    vector<int> matrixDiagonally(vector<vector<int>>&a)
    {
        int n=a.size();
        map<int,vector<int>> mp;
        vector<int> ans;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                mp[i+j].push_back(a[i][j]);
            }
        }
        
        for(auto &it:mp)
        {
            if(it.first % 2 == 0)
                reverse(it.second.begin(),it.second.end());
                
        }
        for(auto &it:mp)
        {
            for(auto j:it.second)
            {
                ans.push_back(j);
            }
        }
        return ans;         
    }
};


//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n;
        int k=0;
        //cin>>k;
        cin>>n;
        vector<vector<int>>mat(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }
        Solution obj;
        vector<int>ans = obj.matrixDiagonally(mat);
        for(auto i: ans)cout << i << " ";
        cout << "\n";
        
       
    }
}
// } Driver Code Ends