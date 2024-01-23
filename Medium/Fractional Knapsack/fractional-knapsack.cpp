//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    static bool comp(Item A, Item B)
    {
        double ratioA = (double) A.value / A.weight;
        double ratioB = (double) B.value / B.weight;
        
        return ratioA > ratioB;
    }
    //Function to get the maximum total value in the knapsack
    
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr, arr + n, comp);
        
        double maxValue = 0;
        for(int i = 0; i < n; i++)
        {
            if(arr[i].weight <= W)
            {
                W -= arr[i].weight;
                maxValue += arr[i].value;
            }
            else
            {
                double frac = (double) W / arr[i].weight;
                maxValue += frac * arr[i].value;
                break;
            }
        }
        
        return maxValue;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(6)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends