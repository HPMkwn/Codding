#include <bits/stdc++.h>
using namespace std;

void rearrangePositiveNegative(int arr[], int n) {
    int pivot = 0;

    int i = 0, j = n - 1;

    while (i <= j) {
        if (arr[i] < pivot)
            i++;
        else
            swap(arr[i], arr[j--]);
    }

    j = 0;
    while (i < n && arr[j] < pivot) {
        swap(arr[i], arr[j]);
        j += 2;
        i++;
    }
}

int main() { return 0; }