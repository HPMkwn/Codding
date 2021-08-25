#include <bits/stdc++.h>
using namespace std;

int numberofDifferentSubString(const string& s, const string& charset,
                               int maxchar) {
    int n = s.length();

    const int p = 31;
    const int m = 1e9 + 9;

    vector<long long> power(n + 1), hash(n + 1);
    power[0] = 1;

    for (int i = 0; i < n; i++) {
        power[i + 1] = (power[i] * p) % m;
    }

    for (int i = 0; i < n; i++) {
        hash[i + 1] = (hash[i] + (s[i] - 'a' + 1) * power[i]) % m;
    }

    int count = 1;

    unordered_set<long long> bucket;
    for (int i = 1; i <= n; i++) {
        map<char, int> mp;
        int curbadwords = maxchar;
        for (int j = i; j <= n; j++) {
            mp[s[j - 1]]++;
            if ('0' == charset[s[j - 1] - 'a']) {
                curbadwords--;
                if (curbadwords < 0) break;
            }
            long long cur_hash = (hash[j] - hash[i - 1] + m) % m;
            bucket.insert((cur_hash * power[n - i]) % m);
        }
    }

    return bucket.size();
}

int main() {
    string s, charset;
    int maxchar;
    cin >> s >> charset;
    cin >> maxchar;
    cout << numberofDifferentSubString(s, charset, maxchar)<<"\n";
    return 0;
}