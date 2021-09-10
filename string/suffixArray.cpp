#include <bits/stdc++.h>
using namespace std;

vector<int> sortCyclicShift(const string& s) {
    int n = s.length();
    const int alphabet = 256;

    vector<int> p(n), c(n), cnt(max(alphabet, n), 0);

    for (int i = 0; i < n; i++) cnt[s[i]]++;

    for (int i = 0; i < alphabet; i++) cnt[i] += cnt[i - 1];

    for (int i = 0; i < n; i++) p[--cnt[s[i]]] = i;

    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i - 1]]) classes++;
        c[p[i]] = classes - 1;
    }

    vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0) pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++) cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++) cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; i--) p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i - 1]], c[(p[i - 1] + (1 << h)) % n]};
            if (cur != prev) ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}

// O(n*logn)
vector<int> suffix_array_construction(string s) {
    s += "$";
    vector<int> sorted_shifts = sortCyclicShift(s);
    sorted_shifts.erase(sorted_shifts.begin());
    return sorted_shifts;
}

vector<int> suffix_array(string s) {
    s += "$";

    int n = s.length();
    int alphabets = 256;

    vector<int> p(n), c(n), cnt(max(n, alphabets));

    for (int i = 0; i < n; i++)cnt[s[i]]++;
    for (int i = 0; i < alphabets; i++)cnt[i] += cnt[i - 1];
    for (int i =0; i <n; i++)p[--cnt[s[i]]] = i;
    
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i - 1]]) classes++;
        c[p[i]] = classes - 1;
    }

    vector<int> cn(n), pn(n);
    for(int h=0; (1<<h)< n;h++){
        for(int i=0;i<n;i++)pn[i] = (p[i] - (1<<h) + n)%n;

        fill(cnt.begin(),cnt.end(),0);
        for(int i=0;i<n;i++)cnt[c[pn[i]]]++;
        for(int i=1;i<classes;i++)cnt[i] += cnt[i-1];
        for(int i=n-1;i>=0;i--)p[--cnt[c[pn[i]]]] = pn[i];

        cn[p[0]] = 0;
        classes = 1;
        for(int i=0;i<n;i++){
            pair<int,int> cur = {c[p[i]], c[(p[i] + (1<<h)%n)]};
            pair<int,int> prev = {c[p[i-1]], c[(p[i-1] + (1<<h)%n)]};
            if(cur != prev)classes++;
            cn[p[i]] = classes-1;
        }
        c.swap(cn);
    }
    return p;
}

int main() {
    vector<int> arr = suffix_array("abcabcabc");

    arr.erase(arr.begin());
    for (auto x : arr) cout << x << "\n";
    return 0;
}