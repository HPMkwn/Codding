#include <bits/stdc++.h>
using namespace std;

void swapfunc(int &a, int &b) {
    int c = b;
    a = b;
    b = c;
}

void print(vector<int> arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void shiftDown(vector<int> &arr, int cur, int end) {
    int left = (cur << 1) + 1;
    while (left <= end) {
        int right = (cur << 1) + 2;
        right = right <= end ? right : -1;

        int idxToSwap;
        if (right != -1 && arr[right] > arr[left]) {
            idxToSwap = right;
        } else {
            idxToSwap = left;
        }

        if (arr[cur] < arr[idxToSwap]) {
            swap(arr[cur], arr[idxToSwap]);
            cur = idxToSwap;
            left = (cur << 1) + 1;
        } else {
            return;
        }
    }
}

void buildheap(vector<int> &arr) {
    int start = (arr.size()) / 2;
    for (int i = start; i >= 0; i--) {
        shiftDown(arr, i, arr.size() - 1);
    }
}
void heapsort(vector<int> &arr) {
    for (int i = arr.size() - 1; i > 0; i--) {
        swap(arr[i], arr[0]);
        shiftDown(arr, 0, i - 1);
        cout<<"iter : "<<arr.size()-1-i<<" : ";
        print(arr);
    }
}


int main() {
    vector<int> arr({8, 5, 2, 9, 5, 6, 3, 1, 10,15,12,45,36,60,79});

    print(arr);
    buildheap(arr);
    print(arr);
    heapsort(arr);
    print(arr);
    return 0;
}