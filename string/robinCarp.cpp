#include <bits/stdc++.h>
using namespace std;

vector<int> robinCarp(string s, string pt) {
    const int s_size = s.length();
    const int p_size = pt.length();
    const int p = 31;
    const int mod = 1e9 + 9;

    long long hash = 0;

    vector<long long> pows(max(s.length(), pt.length()), 0);
    pows[0] = 1;

    for (int i = 1; i < pows.size(); i++) {
        pows[i] = (pows[i - 1] * p) % mod;
    }

    for (int i = 0; i < pt.length(); i++) {
        hash = (hash + (pt[i] - 'a' + 1) * pows[i]) % mod;
    }

    vector<long long> hashes(s.length() + 1, 0);
    for (int i = 0; i < s.length(); i++) {
        hashes[i + 1] = (hashes[i] + (s[i] - 'a' + 1) * pows[i]) % mod;
    }

    vector<int> occurences;
    for (int i = 0; i < (s.length() + 1 - pt.length()); i++) {
        long long cur_hash = (hashes[i + p_size] + mod - hashes[i]) % mod;

        if (cur_hash == (hash * pows[i]) % mod) {
            occurences.push_back(i);
        }
    }

    return occurences;
}

int main() {
    int t;
    string s, p;
    cin >> t;
    while (t--) {
        cin >> s >> p;
        vector<int> occurences = robinCarp(s, p);
        if (occurences.size()>0) {
            cout<<occurences.size()<<"\n";
            for (auto x : occurences) {
                cout << x+1 << " ";
            }
            cout<<"\n";
        } else
            cout << "Not Found\n";
        cout<<"\n";
    }

    return 0;
}