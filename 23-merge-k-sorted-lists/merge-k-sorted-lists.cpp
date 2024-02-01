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
class compare {
public:
    bool operator()(ListNode* a,ListNode* b) {
        return a->val > b->val;
    }
};
class Solution {
public:
// using min heap
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode* , vector<ListNode*>, compare>pq;

        // process first element of every k LL;
        for(int i=0;i<lists.size();i++){
            ListNode* listhead = lists[i];
            if(listhead!=NULL) pq.push(listhead);
        }
        
        //for new linked list
        ListNode* head = NULL;
        ListNode* tail = NULL;

        while(!pq.empty()){
            ListNode* topNode = pq.top();
            pq.pop();

            // ho skta hai ki topNode jo nikali hai , wo humari first node ho
            if(head==NULL){
                // phli node insert kar raha hu
                head = topNode;
                tail = topNode;
                if(tail->next!=NULL) pq.push(tail->next);
            }
            else{
                // phli ke baad mai koi node insert kar raha hu
                // that is inser at end in Linked List
                tail->next=topNode;
                tail = topNode;
                if(tail->next!=NULL) pq.push(tail->next);
            }
        }
        return head;
    }
};