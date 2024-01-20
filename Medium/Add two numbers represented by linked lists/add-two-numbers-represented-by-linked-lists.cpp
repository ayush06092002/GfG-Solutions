//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to reverse a linked list
    struct Node* reverseList(struct Node* head)
    {
        Node* curr = head;
        Node* prev = NULL;
        while(curr)
        {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        first = reverseList(first);
        second = reverseList(second);
        Node* h1 = first;
        Node* h2 = second;
        Node* dummyHead = new Node(0);
        Node* curr = dummyHead;
        int x, y, mod, rem = 0, sum;
        while(h1 || h2 || rem)
        {
            if(h1)
                x = h1->data;
            else
                x = 0;
            
            if(h2)
                y = h2->data;
            else
                y = 0;
            
            sum = x + y + rem;
            
            rem = sum / 10;
            sum = sum % 10;
            
            curr->next = new Node(sum);
            curr = curr->next;
            
            if(h1)
                h1 = h1->next;
            if(h2)
                h2 = h2->next;
        }
        
        return reverseList(dummyHead->next);
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends