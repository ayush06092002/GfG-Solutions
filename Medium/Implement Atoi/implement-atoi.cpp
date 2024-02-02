//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        int sign = (s[0] == '-') ? -1 : 1;
        int result = 0;
        int i = 0;
        if(s[i] == '-')
            i++;
        while (i < s.size() ) {
            if(!(s[i] >= '0' && s[i] <= '9'))
                return -1;
            int digit = s[i] - '0';
    
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > INT_MAX % 10)) {
                return -1;
            }
    
            result = result * 10 + digit;
            i++;
        }      
        
        return result * sign;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends