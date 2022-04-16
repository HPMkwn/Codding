#include<bits/stdc++.h>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    TreeNode* ret;

    bool lca(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root)return false;

        bool left=false,right=false,cur=false;
        if(root->left)left = lca(root->left,p,q);
        if(root==p || root==q)cur = true;
        if(root->right)right = lca(root->right,p,q);

        if(left&&right || cur&&right || cur&&left){this->ret = root; return false;}
        if(left || right || cur)return true;
        return false;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        this->ret = nullptr;
        this->lca(root,p,q);
        return ret;
    }
};


///  make parent variable also 

class BinaryTree{
    struct Node{
        int data;
        Node *left, *right, *parent;

        Node(int _data):data(_data),left(NULL),right(NULL),parent(NULL){}
    };

    Node* head = NULL;

    Node* insert(Node* node, int key){

        if(node == NULL)return new Node(key);

        if(key < node->data){
            node->left = insert(node->left,key);
            node->left->parent = node;
        }else if(key > node->data){
            node->right = insert(node->right,key);
            node->right->parent = node;
        }

        return node;
    }

    Node* lca(Node* child1, Node* child2){

        map<Node*, bool> mp;
        
        while(child1 != NULL){
            child1 = child1->parent;
            mp.insert({child1,true});
        }

        while(child2!=NULL){
            if(mp.count(child2))return child2;
            child2 = child2->parent;
        }

        return NULL;
    }

    Node* lacUsingKey(Node* root,int key1,int key2, Node* ancestor){

        if(!root)return NULL;

        Node* cur = nullptr;
        if(root->data == key1 || root->data == key2)cur = root;

        Node *left=nullptr,*right=nullptr;
        if(root->left)left = lacUsingKey(root->left,key1,key2,ancestor);
        if(root->right)right = lacUsingKey(root->right,key1,key2,ancestor);

        if((cur && left) || (cur && right) || (left && right)){
            ancestor = root;
            cout<<root->data<<"\n";
        }
        return (cur!=nullptr ? cur : (left!=nullptr ? left : right));
    }

    void printTree(Node* root){
        if(!root)return;
        
        printTree(root->left);
        cout<<root->data<<" ";
        printTree(root->right);
    }

    void preOrder(Node* root){
        if(!root)return;

        cout<<root->data<<",";
        preOrder(root->left);
        preOrder(root->right);
    }

    void printPreTree(Node* root){
        
        queue<Node*> q;

        q.push(root);

        while(!q.empty()){
            
            int count = q.size();
            while(count--){
                Node* top = q.front();
                q.pop();
                if(top->left)q.push(top->left);
                if(top->right)q.push(top->right);
                cout<< top->data<<", ";
            }
            cout<<"\n";
        }
    }

    public:
    BinaryTree(){}

    void construct(){
        Node* root = NULL;

        root = insert(root, 12);
        root = insert(root, 20);
        root = insert(root, 10);
        root = insert(root, 8);
        root = insert(root, 22);
        root = insert(root, 4);
        root = insert(root, 14);

        Node* anc = NULL;
        lacUsingKey(root,10,4,anc);
        if(anc!=NULL)
            cout<<(anc)->data<<"\n";

    }

};

int main(int argc, char const *argv[])
{
    BinaryTree tree;
    tree.construct();
    return 0;
}


