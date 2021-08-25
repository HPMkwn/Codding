#include <bits/stdc++.h>
using namespace std;

string defangIPaddr(string address) {
    regex s("\\.");

    string ret;
    
    regex_replace(back_inserter(ret),address.begin(),address.end(),s,"[.]");

    return ret;
}

int main() { 
    
    string str = "1.1.1.1";
    cout<<defangIPaddr(str)<<"\n";
    return 0; }