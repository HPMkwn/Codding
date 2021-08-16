#include <bits/stdc++.h>
using namespace std;

string interpret(string command) {
    regex s("\\(\\)");
    regex al("\\(al\\)");
    
    string ret;
    string end;
    regex_replace(back_inserter(ret),command.begin(),command.end(),s,"o");
    regex_replace(back_inserter(end),ret.begin(),ret.end(),al,"al");

    return end;
}

string interpretII(string command) {
    
        int i=0;
        string ret;
        while(command[i]!='\0'){

            if(command[i]=='G'){ret += command[i];i++;}
            else if(command[i]== '(' && command[i]==')'){
                ret += 'o';
                i += 2;
            }else{
                ret += 'a' + 'l';
                i += 4;
            }
        }
        return ret;
}

int main() { return 0; }