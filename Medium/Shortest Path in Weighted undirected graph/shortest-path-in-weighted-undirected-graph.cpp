//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n + 1, 1e9);
        pq.push({0, 1});
        dist[1] = 0;
        vector<pair<int, int>> adj[n + 1];
        
        vector<int> parent(n + 1);
        for(int i = 1; i <= n; i++)
        {
            parent[i] = i;
        }
        for(int i = 0; i < m; i++)
        {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        while(!pq.empty())
        {
            pair<int, int> p = pq.top();
            int wt = p.first;
            int u = p.second;
            pq.pop();
            
            for(auto it : adj[u])
            {
                int adjNode = it.first;
                int eW = it.second;
                
                if(dist[adjNode] > wt + eW)
                {
                    dist[adjNode] = wt + eW;
                    pq.push({dist[adjNode], adjNode});
                    parent[adjNode] = u;
                }
            }
        }
        
        if(dist[n] == 1e9)
        {
            return {-1};
        }
        
        vector<int> res;
        int node = n;
        while(parent[node] != node)
        {
            res.push_back(node);
            node = parent[node];
        }
        res.push_back(1);
        reverse(res.begin(), res.end());
        
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends