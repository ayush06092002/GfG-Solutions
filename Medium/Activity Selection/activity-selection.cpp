//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    bool static comp(pair<int, int> a, pair<int, int> b){
        return a.second < b.second;
    }
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        vector<pair<int, int>> actPair;
        for(int i = 0; i < n; i++){
            actPair.push_back({start[i], end[i]});
        }
        
        sort(actPair.begin(), actPair.end(), comp);
        
        int endLim = actPair[0].second;
        int maxAct = 1;
        
        for(int i = 1; i < n; i++){
            if(actPair[i].first > endLim){
                endLim = actPair[i].second;
                maxAct++;
            }
        }
        
        return maxAct;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}

// } Driver Code Ends