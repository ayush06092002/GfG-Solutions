//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void func(vector<int>&ans,bool flag,int n)
    {
        if(flag)
        {
            if(ans.back()==n and ans.size()!=1)
                return;
            int k=ans.back()-5;
            ans.push_back(k);
            if(k<=0)
                func(ans,false,n);
            else
                func(ans,true,n);
                
        }
        else
        {
            if(ans.back()==n and ans.size()!=1)
                return;
            int k=ans.back()+5;
            ans.push_back(k);
            func(ans,false,n);
            
        }
    }
    vector<int> pattern(int N){
        // code here
        if(N <= 0)
            return {N};
        vector<int> ans;
        ans.push_back(N);
        func(ans, true, N);
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.pattern(N);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends