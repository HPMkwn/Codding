#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a, b, c, d;
    set<int> mp;
    while (n--) {
        mp.clear();
        cin>>a>>b>>c>>d;
        mp.insert(a);
        mp.insert(b);
        mp.insert(c);
        mp.insert(d);
        switch (mp.size()) {
            case 4:
            case 3:
                cout << 2 << "\n";
                break;

            case 2:
                if((a==b && c==d) || (a==c && b==d) || (a==d && b==c))cout<<2<<"\n";
                else cout << 1 << "\n";
                break;
            default:
                cout << 0 << "\n";
                break;
        }
    }
    return 0;
}