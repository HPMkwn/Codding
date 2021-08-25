#include <bits/stdc++.h>
using namespace std;

int myAtoi(string s) {

              bool isminus = false;
        bool isdigit=false;
        bool issign=false;
    long val=0;
    for(int i=0;i<s.size();i++){
        if(s[i]<58 && s[i]>47){
            
            val = val*10 + s[i]-48;
            if(val>INT_MAX)return (isminus? INT_MIN:INT_MAX);
            isdigit=true;
        }else if(s[i]=='-' || s[i]=='+'){
            if(issign && !isdigit)break;
            if(issign && isdigit)break;
            if(isdigit)break;
            isminus = s[i]=='-' ? true : false;
            issign=true;
        }else if(s[i]==' '){
            if(issign || isdigit)break;            
        }else if(s[i]=='.')break;
        else{
            if(val==0)return 0;
            else break;
        }
    }
    if(isminus)val *= (-1);
    if(val > INT_MAX)return INT_MAX;
    else if(val < INT_MIN)return INT_MIN;
    return val; 
}

int main() { return 0; }