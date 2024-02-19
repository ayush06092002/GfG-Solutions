//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        priority_queue<int> pq;
        for(int i = 0; i < 26; i++)
        {
            pq.push(freq[i]);
        }
    
        int ans = 0;
        while(k > 0)
        {
            int max = pq.top();
            max--;
            pq.pop();
            pq.push(max);
            k--;
        }
        while(!pq.empty())
        {
            int max = pq.top();
            ans = ans + (max * max);
            pq.pop();
        }
    
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends