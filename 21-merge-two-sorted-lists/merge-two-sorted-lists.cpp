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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* result = NULL;
        ListNode*current = NULL;
        while(list1 != NULL && list2  != NULL)
        {
            if(list1->val < list2->val)
            {
                if(result == NULL)
                {
                    result = list1;
                    current = list1;
                }
                else
                {
                    current -> next = list1;
                    current = list1;
                }
                list1 = list1-> next;
            }
            else
            {
                if(result == NULL)
                {
                    result = list2;
                    current = list2;
                }
                else
                {
                    current -> next = list2;
                    current = list2;
                }
                list2 = list2 -> next;
            }
        }
        while(list1!= NULL)
        {
            if(result == NULL)
            {
                result = list1;
                current = list1;
            }
            else
            {
                current -> next = list1;
                current = list1;
            }
            list1 = list1-> next;
        }
        while(list2!= NULL)
        {
            if(result == NULL)
            {
                result = list2;
                current = list2;
            }
            else
            {
                current -> next = list2;
                current = list2;
            }
            list2 = list2-> next;
        }
        return result;
    }
};