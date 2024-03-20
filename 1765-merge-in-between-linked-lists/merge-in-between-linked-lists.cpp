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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *head = list1;
        ListNode *tail = list1;

        // Move head and tail pointers to the ath and (b+1)th nodes respectively
        for (int i = 0; i < a - 1; ++i) {
            head = head->next;
        }
        for (int i = 0; i < b + 1; ++i) {
            tail = tail->next;
        }

        // Connect the nodes before the removed section with list2
        head->next = list2;

        // Move to the end of list2
        ListNode* temp = list2;
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        // Connect the end of list2 with the nodes after the removed section
        temp->next = tail;

        return list1;
    }
};
