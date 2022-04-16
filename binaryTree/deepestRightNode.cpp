#include <bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    Node *left, *right;
};
  
// returns a new tree Node
Node* newNode(int data)
{
    Node* temp = new Node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}


Node* getDeepestRightLeafNode(Node* root){
    
    if(!root)return root;
    
    queue<Node*> q;
    q.push(root);
    
    
    Node* deepestRight = root;
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        
        if(!temp->left && !temp->right)deepestRight = temp;
        
        if(temp->left)q.push(temp->left);
        if(temp->right)q.push(temp->right);
    }
    
    return deepestRight;
}


int main() {
	Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(6);
    root->right->left->right = newNode(7);
    root->right->right->right = newNode(8);
    root->right->left->right->left = newNode(9);
    // root->right->right->right->right = newNode(10);
  
    Node* result = getDeepestRightLeafNode(root);
    if (result)
        cout << "Deepest Right Leaf Node :: "
             << result->data << endl;
    else
        cout << "No result, right leaf not found\n";
    return 0;
}