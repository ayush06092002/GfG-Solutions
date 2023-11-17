//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class DisjointSet {
   
    public:
     vector<int> parent, rank, size;
        DisjointSet(int n){
            parent.resize(n + 1);
            rank.resize(n + 1, 0);
            size.resize(n + 1, 1);
            for(int i = 0; i <= n; i++)
            {
                parent[i] = i;
            }
        }

        int findUPar(int node)
        {
            if(node == parent[node])
                return node;
            
            return parent[node] = findUPar(parent[node]);
        }

        void unionByRank(int u, int v)
        {
            int ulPar_u = findUPar(u);
            int ulPar_v = findUPar(v);

            if(ulPar_u == ulPar_v)
                return;
            if(rank[ulPar_u] < rank[ulPar_v])
            {
                parent[ulPar_u] = ulPar_v;
            }
            else if(rank[ulPar_v] < rank[ulPar_u])
            {
                parent[ulPar_v] = ulPar_u;
            }
            else
            {
                parent[ulPar_v] = ulPar_u;
                rank[ulPar_u]++;
            }
        }

        void unionBySize(int u, int v)
        {
            int ulPar_u = findUPar(u);
            int ulPar_v = findUPar(v);

            if(ulPar_u == ulPar_v)
                return;
            if(size[ulPar_u] < size[ulPar_v])
            {
                parent[ulPar_u] = ulPar_v;
                size[ulPar_v] += size[ulPar_u];
            }
            else
            {
                parent[ulPar_v] = ulPar_u;
                size[ulPar_u] += size[ulPar_v];
            }
        }
};
class Solution {
    private:
        bool isValid(int a, int b, int x, int y)
        {
            return (a >= 0 && a < x && b >= 0 && b < y);
        }
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        DisjointSet ds(n * m);
        int count = 0;
        vector<int> ans;
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(auto it : operators)
        {
            int row = it[0];
            int col = it[1];
            
            if(vis[row][col] == 1)
            {
                ans.push_back(count);
                continue;
            }
            vis[row][col] = 1;
            
            count++;
            
            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, 1, 0, -1};
            
            for(int i = 0; i < 4; i++)
            {
                int adjR = row + dr[i];
                int adjC = col + dc[i];
                
                if(isValid(adjR, adjC, n, m))
                {
                    if(vis[adjR][adjC] == 1)
                    {   
                        int nodeNo = row * m + col;
                        int adjNodeNo = adjR * m + adjC;
                        if(ds.findUPar(nodeNo) != ds.findUPar(adjNodeNo))
                        {
                            count--;
                            ds.unionBySize(nodeNo, adjNodeNo);
                        }
                    }
                }
            }
            
            ans.push_back(count);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends