//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	sort(arr, arr + n);
    	sort(dep, dep + n);
    	
    	int lastDep = 0;
    	int lastArr = 1;
    	int numPlat = 1;
    	int temp = 1;
    	int i = 1;
    	
    	while(lastArr < n){
    	    if(dep[lastDep] >= arr[lastArr]){
    	        temp++;
    	        numPlat = max(numPlat, temp);
    	        lastArr++;
    	    }
    	    else{
    	        temp--;
    	        lastDep++;
    	    }
    	}
    	
    	return numPlat;
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends