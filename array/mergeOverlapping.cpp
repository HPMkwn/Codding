#include <bits/stdc++.h>
using namespace std;

bool isOverlapping(vector<int> &a, vector<int> &b) { return a[1] < b[0]; }

bool isSmall(vector<int> &a, vector<int> &b) { return a[0] < b[0]; }

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> intervals) {
    sort(intervals.begin(), intervals.end(), isSmall);

    vector<vector<int> *> mergedIntervals;
    vector<int> *currentInterval = &intervals[0];

    mergedIntervals.push_back(currentInterval);

    for(auto &nextInterval : intervals){
        int currentEnd = currentInterval->at(1);
        int nextStart = nextInterval.at(0);
        int nextEnd = nextInterval.at(1);

        if(currentEnd >= nextStart){
            currentInterval->at(1) = max(currentEnd,nextEnd);
        }else{
            currentInterval = &nextInterval;
            mergedIntervals.push_back(currentInterval); 
        }
    }

    vector<vector<int>> ret;

    for(auto interval : mergedIntervals){
        ret.push_back(*interval);
    }
    return ret;
}