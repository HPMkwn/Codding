#include <bits/stdc++.h>
using namespace std;

bool isMatchUtils(string s, string p, int i, int j) {
        if (i == s.length() && j == p.length()) return true;
        if (i == s.length() || j == p.length()) {
            if (i == s.length()) {
                if (j + 1 < p.length() && p[j + 1] == '*')
                    return isMatchUtils(s, p, i, j + 2);
                else
                    false;
            } else
                false;
        }
        
        if (j + 1 < p.length() && p[j + 1] == '*') {
            if (s[i] == p[j]) {
                return isMatchUtils(s, p, i + 1, j) || isMatchUtils(s,p,i, j+2);
            } else if (p[j] == '.')
                return isMatchUtils(s, p, i + 1, j) || isMatchUtils(s,p,i,j+2);
            else {
                return isMatchUtils(s, p, i, j + 2);
            }
        } else if (p[j] == '.') {
            return isMatchUtils(s, p, i + 1, j + 1);
        } else {
            if (p[j] == s[i]) {
                return isMatchUtils(s, p, i + 1, j + 1);
            } else
                return false;
        }
        return false;
}

bool isMatch(string s, string p) { return isMatchUtils(s, p, 0, 0); }
int main() {
    string s = "aaaaaaaaaaaaab", p = "a*a*a*a*a*a*a*a*a*a*c";
    cout << isMatch(s, p);
    return 0;
}