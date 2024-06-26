//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      unordered_set<int> st(arr, arr + N);
      int currLength = 1, maxi = 0;
      int i = 0;
      while(i < N){
          int curr = arr[i];
          if(st.find(curr - 1) == st.end()){
              while(st.find(curr + 1) != st.end()){
                  currLength++;
                  curr++;
              }
              
              maxi = max(maxi, currLength);
              currLength = 1;
          }
          i++;
      }
      
      return maxi;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends