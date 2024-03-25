//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    void solve(vector<string> &res, string temp, int n, int countOfOne, int index)
    {
        if(countOfOne < (temp.size() + 1) / 2)
            return;
        
        if(index == n)
        {
            res.push_back(temp);
            return;
        }
        
        solve(res, temp + "1", n, countOfOne + 1, index + 1);
        solve(res, temp + "0", n, countOfOne, index + 1);
    }
	vector<string> NBitBinary(int n)
	{
	   // string ansString;
	   // for(int i = 0; i < n; i++)
	   // {
	   //     ansString += "1";
	   // }
	    vector<string> result;
	   // result.push_back(ansString);
	   // for(int i = n - 1; i > 0; i--)
	   // {
	   //     string modifiedString = ansString;
	   //     modifiedString[i] = '0';
	   //     result.push_back(modifiedString);
	   // }
	    solve(result, "", n, 0, 0);
	    
	    return result;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends