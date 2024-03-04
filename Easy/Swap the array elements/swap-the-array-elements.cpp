//{ Driver Code Starts
//Initial Template for C++
#include <iostream>
using namespace std;


// } Driver Code Ends
//User function Template for C++

/*Function to swap array elements
* arr : array input
* n : number of elements in array
*/
class Solution{
  public:
    void swapElements(int arr[], int n){
        if(n <= 2)
            return;
        
        int first = arr[0];
        int second = arr[1];
        for(int i = 2; i < n; i++)
        {
            arr[i - 2] = arr[i];
        }
        if(n % 2 == 0)
        {
            arr[n - 2] = first;
            arr[n - 1] = second;
        }
        else
        {
            arr[n - 2] = second;
            arr[n - 1] = first;   
        }
        
        return;
    }
};

//{ Driver Code Starts.

// Driver code to test swapElements
int main() {
	
	int testcase;
	
	cin >> testcase;
	
	while(testcase--){
	    int n;
	    cin >> n;
	    
	    int arr[n];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr[i];
	    }
        Solution obj;
        // calling function to swap the array swap elements
	    obj.swapElements(arr, n);
	    
	    // Printing the modified array
	    for(int i = 0;i<n;i++){
            cout << arr[i] << " ";
        }
	    
	    cout << endl;
	}
	
	return 0;
}
// } Driver Code Ends