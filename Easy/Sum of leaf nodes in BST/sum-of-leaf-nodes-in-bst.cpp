//{ Driver Code Starts
//Author- SAJAL AGRAWAL
//sajal.agrawal1997@gmail.com

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

Node *insert(Node *r,int num);
void preOrderDisplay(Node *r);
void inOrderDisplay(Node *r);
void postOrderDisplay(Node *r);
int search(Node *r, int num);


// } Driver Code Ends
/* The structure of Node
struct Node{
    int data;
    Node *left,*right;
}; */


class Solution
{
    private:
        bool isLeaf(Node* root)
        {
            if(!root)
                return true;
            
            if(!root->left && !root->right)
                return true;
            
            return false;
        }
    public:
        /*You are required to complete below method */
        void addLeaves(Node* root, int &sum)
        {
            if(!root)
                return;
            
            if(isLeaf(root))
                sum += root->data;
            
            addLeaves(root->left, sum);
            addLeaves(root->right, sum);
        }
        int sumOfLeafNodes(Node *root ){
            int sum = 0;
            addLeaves(root, sum);
            
            return sum;
        }
};

//{ Driver Code Starts.

int main(void) {
    int t,n,data;
    scanf("%d",&t);
    while(t--){
        Node *root=NULL;
        scanf("%d",&n);
        //printf("n=%d\n",n);
        while(n--){
            scanf("%d",&data);
            //printf("data=%d\n",data);
            root=insert(root,data);
        }
        //inOrderDisplay(root);
        Solution obj;
        printf("%d\n",obj.sumOfLeafNodes(root));
    }
	return 0;
}

Node *insert(Node *r,int num){
    if(r==NULL){
        r = new Node(num);
    }else{
        if(num<r->data){
            r->left=insert(r->left,num);
        }else{
            r->right=insert(r->right,num);
        }
    }
    return r;
}

void preOrderDisplay(Node *r){
    if(r!=NULL){
        printf("%d ",r->data);
        preOrderDisplay(r->left);
        preOrderDisplay(r->right);
    }
}

void inOrderDisplay(Node *r){
    if(r!=NULL){
        inOrderDisplay(r->left);
        printf("%d ",r->data);
        inOrderDisplay(r->right);
    }
}

void postOrderDisplay(Node *r){
    if(r!=NULL){
        postOrderDisplay(r->left);
        postOrderDisplay(r->right);
        printf("%d ",r->data);
    }
}

int search(Node *r,int num){
    if(r==NULL)return 0;
    else if(r->data==num)return 0;
    else if(r->data > num)
        search(r->left,num);
    else 
        search(r->right,num);
}
// } Driver Code Ends