//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
   string findString(int n, int k) {
        // code here
         // code here
    unordered_set<std::string> visited;
    string startingNode(n - 1, '0');
    vector<int> path;
    dfs(k, startingNode, visited, path);

    stringstream result;
    int totalPaths = pow(k, n);
    for (int i = 0; i < totalPaths; i++) {
        result << path[i];
    }
    result << startingNode;
    return result.str();
}

void dfs(int k, std::string current, std::unordered_set<std::string>& visited, std::vector<int>& path) {
    for (int i = 0; i < k; i++) {
        std::string next = current + static_cast<char>('0' + i);
        if (visited.find(next) == visited.end()) {
            visited.insert(next);
            dfs(k, next.substr(1), visited, path);
            path.push_back(i);
        }
    
    }
    }

};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        cin>>N>>K;
        Solution ob;
        string ans = ob.findString(N, K);
        int ok=1;
        for(auto i:ans){
            if(i<'0'||i>K-1+'0')
                ok=0;
        }
        if(!ok){
            cout<<-1<<endl;
            continue;
        }
        unordered_set<string> st;
        for(int i=0;i+N-1<ans.size();i++){
            st.insert(ans.substr(i,N));
        }
        int tot=1;
        for(int i=1;i<=N;i++)
            tot*=K;
        if(st.size()==tot)
        {
            cout<<ans.size()<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
    return 0;
} 
// } Driver Code Ends