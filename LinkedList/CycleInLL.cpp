// Leetcode 141 : Linked List cycle
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

 class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                return true;
            }
        }

        return false;
    }

// Leetcode 142. Linked List Cycle II
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                slow = head;
                ListNode* prev = NULL;

                while(slow != fast) {
                    slow = slow->next;
                    prev = fast;
                    fast = fast->next;
                }

                prev->next = NULL;
                return slow;
            }
        }

        return NULL;
    }
};