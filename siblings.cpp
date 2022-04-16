#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(a, b, i) for (int i = a; i < b; i++)
#define rrep(a, b, i) for (int i = a; i >= b; i--)
#define m 1000000007


struct node{
    int val;
    node* left;
    node* right;

    node(int val):val(val){}
};

pair<int, node*> isSiblingHelper(node* head,node *child){

    queue<pair<node*,pair<int,node*>>> q;
    q.push({head,{0,nullptr}});

    while(!q.empty()){
        
        pair<node*,pair<int,node*>> top = q.front();
        q.pop();
        if(child==top.first){
            return top.second;
        }

        if(top.first->left)q.push({top.first->left,make_pair(top.second.first+1,top.first)});
        if(top.first->right)q.push({top.first->right,{top.second.first+1,top.first}});
    }

    return {-1,nullptr};
}

bool isSiblings(node* head, node* child1, node* child2){

    pair<int, node*> outChild1 = isSiblingHelper(head,child1);
    pair<int, node*> outChild2 = isSiblingHelper(head,child2);

    if(outChild1.first == outChild2.first && outChild1.second!= outChild2.second)return true;

    return false;
}


int main(){

    node* head = new node(1);
    head->left = new node(2);
    head->right = new node(3);
    head->left->left = new node(2);
    head->left->right = new node(5);
    head->right->left = new node(6);
    head->right->right = new node(9);

    cout<<isSiblings(head, head->right->right,head->right->right)<<"\n";
    return 0;
}