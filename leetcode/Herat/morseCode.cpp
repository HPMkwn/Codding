#include <bits/stdc++.h>
using namespace std;

int uniqueMorseRepresentations(vector<string>& words) {

    string arr[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

    unordered_set<string> s;

    for(int i=0;i<words.size();i++){
        string str;
        for(char ch : words[i]){
            str += arr[ch-97];
        }
        s.insert(str);
    }

    return s.size();
}
int main() { return 0; }