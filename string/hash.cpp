#include<bits/stdc++.h>
using namespace std;

long long toHash(const string &s){
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value =0;
    long long p_pow = 1;

    for(char ch : s){
        hash_value = (hash_value + (ch - 'a' + 1)*p_pow) % m;
        p_pow = (p_pow * p)%m;
    }
    return hash_value;
}

vector<long long> hashOfSubstring(const string& s){

    vector<long long> hashvalues;

    const int p=31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow{1};

    for(int i=0;i<s.length();i++){
        hash_value = (hash_value + (s[i] - 'a' +1)*p_pow) % m;
        hashvalues[i] = hash_value;
        p_pow = (p_pow * p)%m;
    }

    return hashvalues;
}

vector<vector<int>> group_identical_strings(vector<string> strings){

    vector<pair<long long ,int>> bucket(strings.size());
    for(int i=0;i<strings.size();i++){
        bucket[i] = {toHash(strings[i]),i};
    }

    sort(bucket.begin(),bucket.end());
    vector<vector<int>> distinct;
    for(int i=0;i<strings.size();i++){
        if(i==0 || bucket[i].first != bucket[i-1].first)distinct.emplace_back();

        distinct.back().push_back(bucket[i].second);
    }

    return distinct;
}

int numberofDifferentSubString(const string& s){
    int n = s.length();

    const int p =31;
    const int m = 1e9 + 9;

    vector<long long> power(n+1), hash(n+1);
    power[0] = 1;

    for(int i=0;i<n;i++){
        power[i+1] = (power[i] * p)%m;
    }

    for(int i=0;i<n;i++){
        hash[i+1] = (hash[i] + (s[i] - 'a' + 1) * power[i])%m;
    }

    int count = 1;

    for(int l=1;l<n;l++){
        set<long long> s;
        for(int i=0;i<n-l;i++){
            long long cur = (hash[i+l] - hash[i] + m)%m;
            cur = (cur * power[n-i-1]) %m;
            s.insert(cur);    
        }
        count += s.size();
    }
    return count;
}

int main(){
    return 0;
}