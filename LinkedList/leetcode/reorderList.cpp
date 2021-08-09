#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* newList = NULL;
    ListNode* cur = head;
    ListNode* next = NULL;
    while (cur) {
        next = cur->next;
        cur->next = newList;
        newList = cur;
        cur = next;
    }

    return newList;
}

void reorderList(ListNode* head) {
    if (!head || !head->next || !head->next->next) return;

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* rev = slow->next;
    slow->next = NULL;
    rev = reverseList(rev);
    ListNode* cur = head;

    ListNode* ret = new ListNode(-1);
    ListNode* temp = ret;
    while (rev && cur) {
        ret->next = cur;
        cur = cur->next;
        ret = ret->next;
        ret->next = rev;
        rev = rev->next;
        ret = ret->next;
    }

    if (cur) {
        ret->next = cur;
    }
    if (rev) {
        ret->next = rev;
    }
    head = temp->next;
}