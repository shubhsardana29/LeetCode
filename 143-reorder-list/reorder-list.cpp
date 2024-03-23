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
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return;

        ListNode* middle = findMiddle(head);
        ListNode* secondHalf = reverseList(middle->next);
        middle->next = nullptr; // break the list into two halves

        mergeLists(head, secondHalf);
    }

    // Function to find the middle of the list
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    // Function to reverse a list
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

    // Function to merge two lists alternately
    void mergeLists(ListNode* l1, ListNode* l2) {
        while (l1 != nullptr && l2 != nullptr) {
            ListNode* temp1 = l1->next;
            ListNode* temp2 = l2->next;

            l1->next = l2;
            l2->next = temp1;

            l1 = temp1;
            l2 = temp2;
        }
    }
};