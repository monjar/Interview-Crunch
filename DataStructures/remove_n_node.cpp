//Question Link:https://leetcode.com/explore/interview/card/google/60/linked-list-5/3064/


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* nthNodeUpdate = head;
        ListNode* listIterator = head;
        
        for(int i = 0; i < n; i++)
            listIterator = listIterator->next;
        
        
        if(listIterator==nullptr)
            return head->next;
        
        while(listIterator->next != nullptr){
            nthNodeUpdate = nthNodeUpdate->next;
            listIterator = listIterator->next;
        }
        
     
        nthNodeUpdate->next = nthNodeUpdate->next->next;
        return head;
    }
};