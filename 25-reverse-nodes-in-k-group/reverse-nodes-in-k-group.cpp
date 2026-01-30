/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(NULL) {}
 *     ListNode(int x) : val(x), next(NULL) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head, ListNode* stop) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next1 = NULL;

        while (curr != stop) {
            next1 = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next1;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode dummy(0);
        dummy.next = head;

        ListNode* groupPrev = &dummy;

        while (true) {
            ListNode* kth = groupPrev;
            for (int i = 0; i < k && kth; i++) {
                kth = kth->next;
            }
            if (!kth) break;

            ListNode* groupNext = kth->next;
            ListNode* groupStart = groupPrev->next;

            ListNode* newHead = reverseList(groupStart, groupNext);

            groupPrev->next = newHead;
            groupStart->next = groupNext;

            groupPrev = groupStart;
        }

        return dummy.next;
    }
};
