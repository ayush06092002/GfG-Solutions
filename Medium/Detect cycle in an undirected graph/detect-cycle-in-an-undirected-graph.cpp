//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool checkBfs(int i, int V, vector<int> adj[], vector<bool> &vis){
        queue<int> q;
        vector<int> parent(V);
        q.push(i);
        vis[i] = true;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto it : adj[node]){
                if(!vis[it]){
                    vis[it] = true;
                    q.push(it);  
                    parent[it] = node;
                }
                else if(parent[node] != it){
                    return true;
                }
            }
        }
        
        return false;
    }
    
    bool checkDfs(int i, int V, vector<int> adj[], vector<bool> &vis, int parent){
        vis[i] = true;
        
        for(auto it : adj[i]){
            if(!vis[it]){
                if(checkDfs(it, V, adj, vis, i))
                    return true;
            }
            
            else if(it != parent){
                return true;
            }
        }
        
        return false;
    }
    
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> vis(V, false);
        
        // for(int i = 0; i < V; i++){
        //     if(!vis[i] && checkBfs(i, V, adj, vis)){
        //         return true;
        //     }
        // }
        
        for(int i = 0; i < V; i++){
            if(!vis[i] && checkDfs(i, V, adj, vis, -1)){
                return true;
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends