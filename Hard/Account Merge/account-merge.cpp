//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class DisjointSet {
    vector<int> parent, rank, size;

    public:
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
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> mp;
        for(int i = 0; i < n; i++)
        {

            for (int j = 1; j < accounts[i].size(); j++) 
            {
                string mail = accounts[i][j];
                if (mp.find(mail) == mp.end()) 
                {
                    mp[mail] = i;
                }
                else 
                {
                    ds.unionBySize(i, mp[mail]);
                }
            }
            
        }
        vector<string> mergedMail[n];
        for (auto it : mp) 
        {
            string mail = it.first;
            int node = ds.findUPar(it.second);
            mergedMail[node].push_back(mail);
        }

        vector<vector<string>> ans;

        for (int i = 0; i < n; i++) 
        {
            if (mergedMail[i].size() == 0) 
                continue;
            sort(mergedMail[i].begin(), mergedMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto it : mergedMail[i]) 
            {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<vector<string>> accounts;

    for (int i = 0; i < n; i++)
    {
      vector<string> temp;
      int x;
      cin >> x;

      for (int j = 0; j < x; j++)
      {
        string s1;
        cin >> s1;
        temp.push_back(s1);
      }
      accounts.push_back(temp);
    }

    Solution obj;
    vector<vector<string>> res = obj.accountsMerge(accounts);
    sort(res.begin(), res.end());
    cout << "[";
    for (int i = 0; i < res.size(); ++i)
    {
      cout << "[";
      for (int j = 0; j < res[i].size(); j++)
      {
        if (j != res[i].size() - 1)
          cout << res[i][j] << ","
               << " ";
        else
          cout << res[i][j];
      }
      if (i != res.size() - 1)
        cout << "], " << endl;
      else
        cout << "]";
    }
    cout << "]"
         << endl;
  }
}
// } Driver Code Ends