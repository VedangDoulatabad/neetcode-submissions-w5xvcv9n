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

    // Find the first middle node
    ListNode* findMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    // Reverse a linked list
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    // Merge two lists alternately
    void merge(ListNode* list1, ListNode* list2) {
        while (list1 != nullptr && list2 != nullptr) {
            ListNode* next1 = list1->next;
            ListNode* next2 = list2->next;

            list1->next = list2;

            if (next1 == nullptr)
                break;

            list2->next = next1;

            list1 = next1;
            list2 = next2;
        }
    }

    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return;

        // Step 1: Find middle
        ListNode* mid = findMid(head);

        // Step 2: Split into two halves
        ListNode* second = mid->next;
        mid->next = nullptr;

        // Step 3: Reverse second half
        second = reverse(second);

        // Step 4: Merge alternately
        merge(head, second);
    }
};