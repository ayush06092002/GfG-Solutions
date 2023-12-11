//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here
        long sum = 0;
        long curr = 0;
        
        for(int i = 0; i < K; i++)
        {
            curr += Arr[i];
        }
        
        sum = curr;
        
        for(int i = K, l = 0; i < N && l < N; i++, l++)
        {
            curr -= Arr[l];
            curr += Arr[i];
            
            sum = max(sum, curr);
        }
        
        return sum;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends