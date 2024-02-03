/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // bool slowFastApproach(ListNode *head){
    //     ListNode * slow = head;
    //     ListNode * fast = head;

    //     while(fast!=NULL){
    //         fast=fast->next;
    //         if(fast!=NULL){
    //             fast=fast->next;
    //             slow=slow->next;

    //         }
    //         // check loop
    //         if(fast==slow){
    //             return true;
    //         }
    //     }
    //     return false;
        
    // }
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode *,bool>tableMap;
        ListNode * temp = head;
        while(temp!=NULL){
            //address check
            if(tableMap.find(temp)!=tableMap.end()){
                //cycle present
                return true;
            }
            else{
               //node not visited beforehand
                tableMap[temp]=true;
            }
            temp=temp->next;
        } 
        // cycle/loop not present
        return false;

        // return slowFastApproach(head);
    }
};