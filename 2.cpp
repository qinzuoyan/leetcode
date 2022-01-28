// Copyright (c) 2019 xiaomi.com, Inc. All Rights Reserved.

#include <cstdlib>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* root = new ListNode(0);
        ListNode* tail = root;
        int jin = 0;
        while (l1 || l2) {
            if (l1) {
                jin += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                jin += l2->val;
                l2 = l2->next;
            }
            tail->next = new ListNode(jin % 10);
            tail = tail->next;
            jin = jin / 10;
        }
        if (jin > 0) { // forgot this case
            tail->next = new ListNode(jin);
        }
        ListNode* result = root->next;
        delete root;
        return result;
    }
};

/* vim: set ts=4 sw=4 sts=4 tw=100 */
