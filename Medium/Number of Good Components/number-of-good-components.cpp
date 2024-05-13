//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
  void dfs(int st,vector<vector<int>> &adj, vector<int> &vis, int &v_count, int &e_count )
    {
        v_count++;
        vis[st] = 1;
        for(auto it:adj[st])
        {
            if(vis[it] == 0)
            {
                
                dfs(it,adj,vis,v_count,e_count);
            }
            e_count++;
        }
    }
    int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges) 
    {
        vector<vector<int>> adj(v+1);

        int ans = 0;
        for(int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> vis(v+1,0);
        for(int i = 1; i <= v; i++)
        {
            int v_count = 0;
            int e_count = 0;
            if(vis[i] == 0)
            {

                dfs(i, adj, vis, v_count, e_count);
                if( e_count == (v_count)*(v_count-1) )
                {
                    ans++;
                }
               
            }
           
         
        }

        return ans;
        // code here
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int e;
        scanf("%d", &e);

        int v;
        scanf("%d", &v);

        vector<vector<int>> edges(e, vector<int>(2));
        Matrix::input(edges, e, 2);

        Solution obj;
        int res = obj.findNumberOfGoodComponent(e, v, edges);

        cout << res << endl;
    }
}

// } Driver Code Ends