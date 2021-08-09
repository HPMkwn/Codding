#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
ListNode* insertionSortList(ListNode* head) {
    if(!head || !head->next)return head;

    ListNode* ret = new ListNode(-1);

    while (head)
    {
        ListNode* temp = ret;
        while(temp->next && head->val < temp->next->val){
            temp = temp->next;
        }
        ListNode* n = head->next;
        if(temp->next->next)
        head->next = temp->next->next;
        else head->next=NULL;        
        temp->next = head;
        head= n;
    }
    return ret->next;    
}
