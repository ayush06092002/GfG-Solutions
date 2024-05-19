//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int findClosest( int n, int k,int arr[]) 
    { 
        int closest = arr[0];
        int low = 0, high = n - 1;
        while(low <= high){
            int mid = (low + high) / 2;
            if((abs(arr[mid] - k) < abs(k - closest)) || 
            (abs(arr[mid] - k) == abs(k - closest) && arr[mid] > closest)){
                closest = arr[mid];
            }
            
            if(arr[mid] < k){
                low = mid + 1;
            }else if(arr[mid] > k){
                high = mid - 1;
            }else{
                return arr[mid];
            }
        }
        
        return closest;
    } 
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(n,k,arr)<<endl;
    }
}

// } Driver Code Ends