#include <iostream>
using namespace std;


void constructBinaryTree(int n,int d,int h){
    if((n>2 && d==1) || (d>2*h)){
        cout<<"Binary tree not possible\n";
        return;
    }
    
    if(d==1 && h==1 && n==2){
        cout<<"1 , 2\n";
        return;
    } 
    
    for(int i=1;i<=h;i++){
        cout<<i<<" , "<<i+1<<"\n";
    }
    
    
    if(d>h){
        cout<< "1 , "<<h+1<<"\n";
        for(int i=h+2;i<=(d);i++){
            cout<<i<<" , "<<i+1<<"\n";
        }
    }
    
    for(int i=d+1;i<=n;i++){
        cout <<"1 , "<<i<<"\n";
    }
}

int main() {
    int n,d,h;
    cin>>n>>d>>h;
    constructBinaryTree(n,d,h);
	return 0;
}