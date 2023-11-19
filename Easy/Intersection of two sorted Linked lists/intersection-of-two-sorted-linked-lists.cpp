//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    if(n)
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    else cout<< " ";
}


// } Driver Code Ends
/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

class Solution
{
    public:
    Node* findIntersection(Node* head1, Node* head2)
    {
        // code goes here.
    Node *newH = NULL;
    unordered_map<int, int> mp;
    Node *curr = head1;
    while(curr != NULL)
    {
        mp[curr->data]++;
        curr = curr->next;
    }
    curr = head2;
    Node* newC = NULL;
    while(curr != NULL)
    {
        if(mp[curr->data] > 0)
        {
            Node* temp = new Node(curr->data);
            if(newH == NULL)
            {
                newH = temp;
                newC = newH;
            }
            else
            {
                newC->next = temp;
                newC = newC->next;
            }
            mp[curr->data]--;
        }
        curr = curr->next;
    }
    return newH;

    }
};



//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>> n >> m;
	    
	    Node* head1 = inputList(n);
	    Node* head2 = inputList(m);
	    
	    Solution ob;
	    Node* result = ob.findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}

// } Driver Code Ends