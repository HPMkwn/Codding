#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

    int numComponents(ListNode* head, vector<int>& nums) {

        set<int> s(begin(nums),end(nums));
        int count=0;
        while (head)
        {
            if(s.find(head->val)==s.end() || (!head->next)){
                count++;
            }
            head = head->next;

        }
        return count;
    }h

