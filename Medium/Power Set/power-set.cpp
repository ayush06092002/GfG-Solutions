//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    void solve(int i, string s, string temp, vector<string> &res)
	    {
	        if(i == s.length())
	        {
	            if(temp.length() > 0)
	                res.push_back(temp);
	               
	            return;
	        }
	        
            solve(i + 1, s, temp, res);
            
            temp += s[i];
            solve(i + 1, s, temp, res);
	    }
		vector<string> AllPossibleStrings(string s){
		    vector<string> res;
		    solve(0, s, "", res);
		    
		    sort(res.begin(), res.end());
		    return res;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends