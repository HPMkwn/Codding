#include <bits/stdc++.h>
using namespace std;


int arrangeCoins(int n) {
    long long i = 0, j = n;

    while (i <= j) {
        long long mid = (i + j) >> 1;
        long long compareVal = ((mid + 1) * (mid + 2)) >> 1;
        if (n > compareVal)
            i = mid + 1;
        else if (n < compareVal)
            j = mid - 1;
        else
            return mid + 1;
    }

    return i;
}

int main() { return 0; }