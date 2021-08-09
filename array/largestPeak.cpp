#include <bits/stdc++.h>
using namespace std;

int longestPeak(vector<int> array) {
    if (array.size() < 3) return 1;
    vector<int> pre(array.size(), 1);
    vector<int> suf(array.size(), 1);

    int max = INT_MIN;

    for (int i = 1; i < array.size(); i++) {
        if (array[i] > array[i - 1]) pre[i] = pre[i - 1] + 1;
    }

    for (int j = array.size() - 2; j >= 0; j--) {
        if (array[j] > array[j + 1]) suf[j] = suf[j + 1] + 1;
    }

    for (int i = 0; i < array.size(); i++) {
        if (pre[i] == 1 || suf[i] == 1) continue;
        int curSum = pre[i] + suf[i] - 1;
        if (curSum >= 3 && curSum > max) max = curSum;
    }

    return max == INT_MIN ? 0 : max;
}

int longestPeakOn(vector<int> arr) {
    int j = -1, k = -1, d = 0;

    if (arr.size() < 3) return 0;

    for (int i = 0; i < arr.size() - 2; i++) {
        if (arr[i] < arr[i + 1]) {
            if (j == -1) {
                k = -1;
                j = i ;
            }
            // j = i;
        } else if (arr[i] > arr[i + 1]) {
            k=i;
            if (j != -1) {
                if (k - j + 1 > d) d = k - j + 1;
            }
        } else {
            j = -1;
        }
    }
    
    if(j!=-1 && k-j+1 >d)d = k-j+1;

    return d;
}

int main() {
    vector<int> arr = {5, 4, 3, 2, 1, 2, 1};
    cout << longestPeak(arr) << "\n" << longestPeakOn(arr);
}