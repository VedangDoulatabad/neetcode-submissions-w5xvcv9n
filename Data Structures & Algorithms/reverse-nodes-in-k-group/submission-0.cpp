/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:

    // Reverse nodes from head up to (but not including) stop
    ListNode* reverse(ListNode* head, ListNode* stop) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != stop) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        if (head == nullptr || k == 1)
            return head;

        ListNode* dummy = new ListNode(0, head);
        ListNode* prevGroupTail = dummy;

        while (true) {

            // Find the kth node
            ListNode* kth = prevGroupTail;

            for (int i = 0; i < k; i++) {
                kth = kth->next;

                if (kth == nullptr)
                    return dummy->next;
            }

            ListNode* groupHead = prevGroupTail->next;
            ListNode* groupNext = kth->next;

            // Reverse current group
            ListNode* newHead = reverse(groupHead, groupNext);

            // Reconnect
            prevGroupTail->next = newHead;
            groupHead->next = groupNext;

            // Move to the next group
            prevGroupTail = groupHead;
        }

        return dummy->next;
    }
};