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
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int, ListNode*> prefixSumMap;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        int prefixSum = 0;
        ListNode* current = dummy;

        while (current != nullptr) {
            prefixSum += current->val;
            prefixSumMap[prefixSum] = current;
            current = current->next;
        }

        // Reset and iterate again to remove nodes
        current = dummy;
        prefixSum = 0;
        while (current != nullptr) {
            prefixSum += current->val;
            current->next = prefixSumMap[prefixSum]->next;
            current = current->next;
        }

        return dummy->next;

        
    }
};