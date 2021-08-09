#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
ListNode* BubbleLinkedList(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* main = head;

    while (main->next) {
        ListNode* temp = head;
        while (temp->next) {
            if (temp->val > temp->next->val) {
                int d = temp->val;
                temp->val = temp->next->val;
                temp->next->val = d;
            }
            temp = temp->next;
        }

        main = main->next;
    }
    return head;
}

