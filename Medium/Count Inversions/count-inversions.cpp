//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
  
    long long int merge(long long start, long long end, long long mid, long long arr[]){
        long long count = 0;
        
        int n1 = mid - start + 1;
        int n2 = end - mid;
        
        long long left[n1];
        long long right[n2];

        for(int i = 0; i < n1; i++){
            left[i] = arr[start + i];
        }
        
        for(int i = 0; i < n2; i++){
            right[i] = arr[mid + 1 + i];
        }
        
        int i = 0, j = 0, k = start;
        while(i < n1 && j < n2){
            if(left[i] <= right[j]){
                arr[k++] = left[i++];
            }
            else{
                arr[k++] = right[j++];
                count += n1 - i;
            }
        }
        
        while(i < n1){
            arr[k++] = left[i++];
        }
        
        while(j < n2){
            arr[k++] = right[j++];
        }
        
        return count;
    }
    
    long long int mergeSort(long long int start, long long int end, long long arr[]){
        if(start >= end){
            return 0;
        }
        
        long long int count = 0;
        int mid = (start + end) / 2;
        count += mergeSort(start, mid, arr);
        count += mergeSort(mid + 1, end, arr);
        count += merge(start, end, mid, arr);
        
        return count;
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        return mergeSort(0, N - 1, arr);
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends