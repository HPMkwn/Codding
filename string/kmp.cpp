#include <bits/stdc++.h>
using namespace std;

bool kmpPatternSearching(string s, string p) {
    if (p.length() == 0) return true;

    // Pi table
    int gotoind[p.length()] = {0};

    for (int i = 1; i < p.length(); i++) {
        int j = 0;
        while (p[i] == p[j]) {
            gotoind[i] = j;
            i++;
            j++;
        }
    }

    int j = 0;
    for (int i = 0; i < s.length();) {
        if (s[i] != p[j]) {
            i++;
            continue;
        }

        while (i < s.length() && j < p.length() && s[i] == p[j]) {
            i++;
            j++;
        }
        if (j >= p.length())
            return true;
        else
            j = gotoind[j];
    }

    return false;
}

vector<int> kmpAllPatternSearching(string s, string p) {
    vector<int> bucket;
    if (p.length() == 0) return bucket;

    // Pi table
    int gotoind[p.length()] = {0};

    for (int i = 1; i < p.length(); i++) {
        int j = 0;
        while (p[i] == p[j]) {
            gotoind[i] = j;
            i++;
            j++;
        }
    }

    int j = 0;
    for (int i = 0; i < s.length();) {
        if (s[i] != p[j]) {
            i++;
            continue;
        }

        while (i < s.length() && j < p.length() && s[i] == p[j]) {
            i++;
            j++;
        }
        if (j >= p.length()) {
            j = gotoind[p.length() - 1];
            bucket.push_back(i - p.length());
            i--;
        } else
            j = gotoind[j];
    }
    return bucket;
}

int main() {
    string s, p;
    // bool istrue=false;
    // int n;
    // while (cin >> n >> p >> s) {
    //     // cout<<n<<" "<<p<<" "<<s<<"\n";
    //     vector<int> buc = kmpAllPatternSearching(s, p);
    //     if (buc.size() > 0) {
    //         if(istrue){cout << "\n";}
    //         for (auto x : buc) cout << x << "\n";
    //     }
    //     istrue = true;
    // }

    // cin>>s>>p;
    // cout<<s<<" "<<p;4
    getline(cin,s);
    getline(cin,p);
    vector<int> buc = kmpAllPatternSearching(s,p);
    cout<<buc.size()<<"\n";
    for(auto x : buc)cout<<x<<" ";

    return 0;
}