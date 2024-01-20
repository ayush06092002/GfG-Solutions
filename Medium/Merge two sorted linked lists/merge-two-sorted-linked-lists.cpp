//{ Driver Code Starts
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* sortedMerge(struct Node* a, struct Node* b);

/* Function to print Nodes in a given linked list */
void printList(struct Node *n)
{
    while (n!=NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

/* Driver program to test above function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        int data;
        cin>>data;
        struct Node *head1 = new Node(data);
        struct Node *tail1 = head1;
        for (int i = 1; i < n; ++i)
        {
            cin>>data;
            tail1->next = new Node(data);
            tail1 = tail1->next;
        }

        cin>>data;
        struct Node *head2 = new Node(data);
        struct Node *tail2 = head2;
        for(int i=1; i<m; i++)
        {
            cin>>data;
            tail2->next = new Node(data);
            tail2 = tail2->next;
        }

        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends


 

/* Link list Node
struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
//Function to merge two sorted linked list.
Node* sortedMerge(Node* head1, Node* head2)  
{  
    Node* mergeHead = NULL;
    Node* list1 = head1, *list2 = head2;
    if(list1 ->data < list2 ->data)
    {
        mergeHead = list1;
        list1 = list1->next;
    }
    else
    {
        mergeHead = list2;
        list2 = list2->next;
    }
    Node *ans = mergeHead;
    Node* temp = NULL;
    while(list1 && list2)
    {
        if(list1->data < list2->data)
        {
            temp = list1;
            mergeHead->next = temp;
            list1 = list1->next;
            mergeHead = mergeHead->next;
        }
        else
        {
            temp = list2;
            mergeHead->next = temp;
            list2 = list2->next;
            mergeHead = mergeHead->next;
        }
    }
    while(list1)
    {
        temp = list1;
        mergeHead->next = temp;
        list1 = list1->next;
        mergeHead = mergeHead->next;
    }
    while(list2)
    {
        temp = list2;
        mergeHead->next = temp;
        list2 = list2->next;
        mergeHead = mergeHead->next;        
    }
    
    return ans;
}  