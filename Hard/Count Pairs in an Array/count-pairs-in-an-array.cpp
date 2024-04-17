//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    long long merge(int arr[], int left, int mid, int right) {
        vector<int> temp(right - left + 1);
        long long inv_count = 0;
    
        int i = left;
        int j = mid + 1;
        int k = 0;
    
        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                inv_count += mid - i + 1;
                temp[k++] = arr[j++];
            }
        }
    
        while (i <= mid) {
            temp[k++] = arr[i++];
        }
    
        while (j <= right) {
            temp[k++] = arr[j++];
        }
    
        for (i = left, k = 0; i <= right; ++i, ++k) {
            arr[i] = temp[k];
        }
    
        return inv_count;
    }

    long long mergeSortAndCountInversions(int arr[], int left, int right) {
        long long inv_count = 0;
        if (left < right) {
            int mid = left + (right - left) / 2;
            inv_count += mergeSortAndCountInversions(arr, left, mid);
            inv_count += mergeSortAndCountInversions(arr, mid + 1, right);
            inv_count += merge(arr, left, mid, right);
        }
        return inv_count;
    }
    int countPairs(int arr[] , int n ) 
    {
        for(int i = 0; i < n; i++)
        {
            arr[i] *= i;
        }
        
        return mergeSortAndCountInversions(arr, 0, n - 1);
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
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	Solution ob;
    	cout<<ob.countPairs(a, n)<<endl;
    }
}
// } Driver Code Ends