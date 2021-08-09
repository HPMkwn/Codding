#include <bits/stdc++.h>
using namespace std;

int getWinner(int g1,int s1,int b1, int g2,int s2, int b2){
    if(g1+s1+b1 > g2+s2+b2)return 1;
    return 2;
}

int main() {
    int n;
    cin>>n;
    int g1, s1, b1, g2, s2, b2;
    while (n--) {
        cin>>g1>>s1>>b1>>g2>>s2>>b2;

        cout<<getWinner(g1,s1,b1,g2,s2,b2)<<"\n";
    }

    return 0;
}