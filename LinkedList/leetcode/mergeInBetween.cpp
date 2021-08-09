#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* getNthNode(ListNode* head, int idx) {
    int i = 1;
    while (i < (idx - 1) && head->next) {
        i++;
        head = head->next;
    }
    return head;
}

ListNode* getTailNode(ListNode* head){

    while (head->next)
    {
        head = head->next;
    }
    
    return head;
}

ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
    ListNode* start = getNthNode(list1,a);
    ListNode* end = getNthNode(list1,b);

    // start->next = end;
    // end = getTailNode(start);
    // end->next = list2;
    start->next = list2;
    start = getTailNode(start);
    start->next = end->next;
    return list1;
}