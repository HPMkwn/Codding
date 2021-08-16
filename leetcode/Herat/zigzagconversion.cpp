#include <bits/stdc++.h>
using namespace std;

string convert(string s, int numRows) {
    int n = s.length();
    vector<vector<int>> store(numRows,vector<int>(n,-1));

    int si=0,i=0,j=0;
    while (si<n)
    {
        while(si<n && i<numRows){
            store[i][j] = s[si];
            i++;
        }

        i--;
        j++;
        while (si<n && i>0)
        {
            store[i][j] = s[si];
            i--;
            j++;
        }
    }

    int len = j;
    string str="";
    for(int i=0;i<numRows;i++){
        for(int j=0;j<len;j++){
            if(store[i][j]!=-1)str+= store[i][j];
        }
    }
    return str;
}

int main() { return 0; }