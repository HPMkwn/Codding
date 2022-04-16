#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, *right;
};
 
// Helper function to allocates a new node
Node* newnode(int data)
{
    Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
 
// Helper function to check if node is leaf node
bool isLeaf(Node *root)
{
    return (root->left == NULL && root->right == NULL);
}


void sink(Node* root){
    if(!root || isLeaf(root))return;
    
    if(root->left && !(root->left->data & 1)){
        swap(root->left->data,root->data);
        sink(root->left);
    }else if(root->right && !(root->right->data & 1)){
        swap(root->right->data,root->data);
        sink(root->right);
    }
}

void sinkOddNodes(Node* root){
    if(!root || isLeaf(root))return;
    
    sinkOddNodes(root->left);
    sinkOddNodes(root->right);
    
    if(root->data & 1)sink(root);
}


void printLevelOrder(Node* root){
    if(!root)return;
    
    std::queue<Node* >q;
    q.push(root);
    
    while(!q.empty()){
        int sizeOfQ = q.size();
        
        while(sizeOfQ--){
            Node* temp = q.front();
            q.pop();
            
            cout<<temp->data<<", ";
            
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
        }
        cout<<"\n";
    }
}

int main() {
    
    
	Node *root = newnode(1);
    root->left = newnode(5);
    root->right    = newnode(8);
    root->left->left = newnode(2);
    root->left->right = newnode(4);
    root->right->left = newnode(9);
    root->right->right = newnode(10);
 
    sinkOddNodes(root);
 
    printf("Level order traversal of modified tree\n");
    printLevelOrder(root);
 
    return 0;
}