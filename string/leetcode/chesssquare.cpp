#include <bits/stdc++.h>
using namespace std;

bool squareIsWhite(string coordinates) {
    if (((coordinates[0] - 'a') + (coordinates[1] - '0')) % 2 == 0) return true;

    return false;
}

int main() { return 0; }