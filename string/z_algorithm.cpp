#include <bits/stdc++.h>
using namespace std;

vector<int> zfunction(string s) {
    int n = (int)s.length();
    vector<int> z(n);

    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        }

        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            ++z[i];
        }

        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }

    return z;
}

vector<int> zAlgorithm(string s) {
    int n = s.length();
    int L = 0, R = 0;
    vector<int> z(n, 0);
    for (int i = 1; i < s.length(); i++) {
        if (i > R) {
            L = R = i;
            while (R < n && s[R - L] == s[R]) R++;
            z[i] = R - L;
            R--;
        } else {
            int k = i - L;
            if (z[i] < R - i + 1)
                z[i] = z[k];
            else {
                L = 1;
                while (R < n && s[R - L] == s[R]) R++;
                z[i] = R - L;
                R--;
            }
        }
    }

    return z;
}

bool prepareString(string s, string p) {
    string prepared = p + '$' + s;

    vector<int> prefixlength = zAlgorithm(prepared);
    
    for (int i = 0; i < prefixlength.size(); i++) {
        if (prefixlength[i] == p.length());
        cout<<prefixlength[i]<<" ";
    }
    return false;
}

int main() {
    cout << (prepareString("aabbbbbbbbbb", "aa") ? "true" : "false") << "\n";
    return 0;
}