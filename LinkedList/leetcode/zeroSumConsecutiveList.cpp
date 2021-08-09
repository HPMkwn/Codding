#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* removeZeroSumSublists(ListNode* head) {

    if(!head || !head->next)return head;

    ListNode* temp = head;

    unordered_map<int,ListNode*> s;
    int sum=0;
    ListNode* puppend = new ListNode(-1);
    puppend->next = head;
    while (puppend->next)
    {
        sum += puppend->next->val;

        if(sum==0){
            return puppend->next->next;
        }
        else if(s.find(sum)!=s.end()){
            ListNode* prev  = s[sum];
            prev->next->next = puppend->next->next;
            s.clear();
            s[sum]=prev;
        }else{
            s[sum] = puppend;
        }
        puppend = puppend->next;
    }
    return head;
}