//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
void dfs(int node, vector<int>& inDegree, vector<int> adj[]) {
    inDegree[node]--;
    for (int neighbor : adj[node]) {
        inDegree[neighbor]--;
        dfs(neighbor, inDegree, adj);
    }
}
	int isEulerCircuit(int V, vector<int>adj[]){
	    // Code here
    // Calculate in-degree of each vertex
    vector<int> inDegree(V, 0);
    for (int i = 0; i < V; i++) {
        for (int neighbor : adj[i]) {
            inDegree[neighbor]++;
        }
    }

    // Count the number of vertices with odd in-degree
    int oddCount = 0;
    int startNode = 0;
    for (int i = 0; i < V; i++) {
        if (inDegree[i] % 2 != 0) {
            oddCount++;
            startNode = i;
        }
    }

    // If there are more than two vertices with odd in-degree, no Eulerian path or circuit
    if (oddCount > 2) {
        return 0;
    }

    // If there are exactly two vertices with odd in-degree, it must be an Eulerian path
    if (oddCount == 2) {
        return 1;
    }

    // If all vertices have even in-degree, it is an Eulerian circuit
    if (oddCount == 0) {
        return 2;
    }

    // If oddCount == 1, it means the graph has an Eulerian path but not a circuit
    // Find the starting node for the Eulerian path
    while (inDegree[startNode] % 2 == 0) {
        startNode++;
    }

    // Perform DFS to check connectivity of the graph and update in-degree
    dfs(startNode, inDegree, adj);

    // Check if all vertices have in-degree 0
    for (int i = 0; i < V; i++) {
        if (inDegree[i] > 0) {
            return 0; // Graph is not connected
        }
    }

    return 1; // Graph has an Eulerian path
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		int ans = obj.isEulerCircuit(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends