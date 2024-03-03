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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
          // Calculate the length of the linked list
        int length = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            length++;
            temp = temp->next;
        }

        // Calculate the position to remove
        int pos = length - n;

        // Handle the case where the head needs to be removed
        if (pos == 0) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        // Traverse to the node before the one to be removed
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (pos > 0) {
            pos--;
            prev = curr;
            curr = curr->next;
        }

        // Remove the node
        prev->next = curr->next;
        delete curr;

        return head;
        
    }
};